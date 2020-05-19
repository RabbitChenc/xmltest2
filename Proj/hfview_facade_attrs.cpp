#include "hfview_facade_attrs.h"
#include <QFile>
#include <QDebug>
#include <QXmlStreamReader>


HFviewFacadeAttrs::HFviewFacadeAttrs()
{
    qDebug() << "view con start " <<endl;

}
HFviewFacadeAttrs::~HFviewFacadeAttrs()
{
    if(btnAttrs!=nullptr){
        delete btnAttrs;
        btnAttrs = nullptr;
    }
    qDebug() << "view decon end~~ " <<endl;
}

int HFviewFacadeAttrs::readXml()
{
    QFile qtFile(fileNAme);
    if(!qtFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
         qDebug()<< "Open failed." << endl;
         return -1;
    }

     m_xmlReader.setDevice(&qtFile);
     while(!m_xmlReader.atEnd()){
          QXmlStreamReader::TokenType token = m_xmlReader.readNext();
          if(token == QXmlStreamReader::StartElement){

            if(m_xmlReader.name() == "Button"){
                qDebug() << m_xmlReader.name()<<endl;
                btnAttrs = new HFButtonFacadeAttrs;

            }
          }
      }

     qDebug()<< "xml file deal.fini" << endl;
     if(m_xmlReader.hasError()){
        qDebug() << "error in file " <<endl;
     }
     qtFile.close();
}


