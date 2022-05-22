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
    fighterAnimation,
    manWalkingSun,
    manPickingFromTree,
    elephant
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
  const char *manWalkingSun = R"(                            .-""""-.
                           F       `Y
                          F          Y
                          L          J          ##
                           L        J          ###
                       #    `-.__.-'          ####
              _____   ##                 .---#####-...__
          .--'     `-###          .--..-'    ######     ""`--- 
 _____.----.        ###`.._____ .'          #######
 a:f                ###       /       -.    ####### _.---
                    ##      : `--...        ######
                     #       `.     ``.     ######
                           _   :       :.    #####
                          ( )            )    ###
                         ,- -.           /    ##
                        |,   .|          |   .##
                        || ' |;         |     '
                     .  ((_, J         <
                   .'    | | |         |
                  /      | ; )         |
                 '       |_ -          .
)";
  const char *manPickingFromTree = R"(             .-__
          .-'   )`-__
          )          \.-.
       .-.-.             )
      /                  \
     |                   /
     \                   (
     |              _    /
     (       -.      \__/C
      \        \       ( |:
       ) U\    |       / || _
       `'  `-._| .-._.'  \ ( )
               | >        \  \
              -< |        )   \
               | |        \  (\\ _____________
               | |        |  ) `|             |
               | |        | /   =             =
               | |        | \   |             |
 a:f_________.-' "-______-'  \__|             |________________________)";
  const char *elephant = R"(                              
                ▄▄▄          
            ▄█▀▀   ▌         
         ▄█▀      █          
  ▄▄▀   █         ▌          
 ██▄▄▄▄█         ▐   ▄▄▄     
  █   ▐▀▀▀▀▀█▄▄▄▄█▀▀▀        
   █  ▐         ▐▀▄          
      ▐         ▌  █         
      ▐▄       █             
       ▀▄     ▀              
         ▀▄▄▄█               
                             

 
)";
  const char *none3 = R"( )";
}

#endif