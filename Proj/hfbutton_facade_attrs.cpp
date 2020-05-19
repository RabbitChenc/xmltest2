#include "hfbutton_facade_attrs.h"
#include <QDebug>
#include <QString>

HFButtonFacadeAttrs::HFButtonFacadeAttrs()
{
    //打开文件成功 才设置属性
    SetAttrs(stateNormal);
    SetAttrs(statePressd);
    SetAttrs(stateDisabled);
}
//获取按键正常状态的属性
const tHFButtonFacadeState* HFButtonFacadeAttrs::GetNormalAttrs()
{
    SetAttrs(stateNormal);
}

const tHFButtonFacadeState* HFButtonFacadeAttrs::GetPressedAttrs()
{
   SetAttrs(statePressd);
}

const tHFButtonFacadeState* HFButtonFacadeAttrs::GetDisabledAttrs()
{
     SetAttrs(stateDisabled);
}


void HFButtonFacadeAttrs::SetAttrs(tHFButtonFacadeState &state)
{
    bool ok0;
    if(attributes.hasAttribute("background")){
        QString backcolor = attributes.value("background").toString() ;
        //需要增加一个对 十六进制还是十进制的判断
        if(backcolor.startsWith("0x") || backcolor.startsWith("0X")){
            state.m_backgroundColor = backcolor.toInt(&ok0,16);
        }else{
            state.m_backgroundColor = backcolor.toInt(&ok0,10);
        }

    }
    if(attributes.hasAttribute("left")){
        QString left = attributes.value("left").toString();
        state.m_leftMargin = left.toInt(&ok0,10);
    }
    if(attributes.hasAttribute("top")){
        QString top = attributes.value("top").toString();
        state.m_topMargin = top.toInt(&ok0,10);
    }
    if(attributes.hasAttribute("right")){
        QString right = attributes.value("right").toString();
        state.m_rightMargin = right.toInt(&ok0,10);
    }
    if(attributes.hasAttribute("bottom")){
        QString bottom = attributes.value("bottom").toString();
        state.m_bottomMargin = bottom.toInt(&ok0,10);
    }
    if(attributes.hasAttribute("text_color")){
        QString text_color = attributes.value("text_color").toString();
        if(text_color.startsWith("0x")|| text_color.startsWith("0X")){
            state.m_textColor = text_color.toInt(&ok0,16);
        }else{
            state.m_textColor = text_color.toInt(&ok0,10);
        }
    }
    debugTest(state);
}


void HFButtonFacadeAttrs::debugTest(tHFButtonFacadeState &state)
{
    qDebug() << state.m_textColor << ";" << state.m_topMargin << ";" << state.m_leftMargin <<";"
             <<state.m_imgFilename <<";" << state.m_rightMargin <<";" << state.m_bottomMargin << ";"
             <<state.m_backgroundColor <<endl;
}




HFButtonFacadeAttrs::~HFButtonFacadeAttrs()
{

}
