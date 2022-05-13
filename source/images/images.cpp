#ifndef IMAGES_H
#define IMAGES_H

namespace imagesEnumb
{
  enum ImageEnumb
  {
    none = 0,
    fighter = 1,
    mage,
    Choose,
    mageAnimation,
    fighterAnimation
  };
}

namespace images
{
  const char *none = R"( )";
  const char *hsutimage = R"(

|==(W{==========-       
    ||  (.--.)         
    | \_,|**fsdfsdf|,__      
    `\ ' `--'   ),     
      `\_. .__/\ \`      
        | .  |~~\~|    
       /==0==-\  /    
      /~\___/~~\/    

    )";

}

#endif