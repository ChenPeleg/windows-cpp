#ifndef IMAGES_H
#define IMAGES_H

namespace imagesEnumb
{
  enum ImageEnumb
  {
    none = 0,
    fighter = 1,
    mage,
    Choose
  };
}

namespace images
{
  char image1[] = "123123";
  const char *fighter = R"(

|==(W{==========-       
    ||  (.--.)         
    | \_,|**|,__      
    `\ ' `--'   ),     
      `\_. .__/\ \`      
        | .  |~~\~|    
       /==0==-\  /    
      /~\___/~~\/    

    )";
  const char *mage = R"(
                                    /\
                                   /  \
                                  |    |
                                --:'''':--
                                  :'_' :
                                  _:"":\___
                    * *      ____.' :::     \.
                   * *=====<<=)           \  :
                    *  *      '-'-'\_     /  |
                                    \====:_ /
                                   .'     \\
                                  :       :
                                 /   :    \
                                 )";
}

#endif