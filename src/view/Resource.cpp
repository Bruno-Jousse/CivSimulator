/**
 * Project Untitled
 */


#include "Resource.h"

/**
 * Ressource implementation
 */
namespace view{

Resource::Resource(int w, int h, QString path){
    img.load(path);
    img = img.scaled(w, h, Qt::KeepAspectRatio);
}

Resource::~Resource(){

}
}
