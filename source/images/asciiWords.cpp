#ifndef ASCIIWORDS_H
#define ASCIIWORDS_H

namespace asciiImages
{
  enum AsciiWordsEnumb
  {
    noword,
    dodge,
    hit,
    blocked,
    youWin

  };
}

namespace images
{
  const char *Wdodge = R"(  
  ___             _              
 |   \   ___   __| |  __ _   ___ 
 | |) | / _ \ / _` | / _` | / -_)
 |___/  \___/ \__,_| \__, | \___|
                     |___/       )";
  const char *Whit = R"( 
  _  _   ___   _____   _ 
 | || | |_ _| |_   _| | |
 | __ |  | |    | |   |_|
 |_||_| |___|   |_|   (_)
                         )";
  const char *Wblocked = R"(  
  ___   _              _              _   _ 
 | _ ) | |  ___   __  | |__  ___   __| | | |
 | _ \ | | / _ \ / _| | / / / -_) / _` | |_|
 |___/ |_| \___/ \__| |_\_\ \___| \__,_| (_)
                                            )";

  const char *WyouWin = R"(
 __   __                          _          _ 
 \ \ / /  ___   _  _    __ __ __ (_)  _ _   | |
  \ V /  / _ \ | || |   \ V  V / | | | ' \  |_|
   |_|   \___/  \_,_|    \_/\_/  |_| |_||_| (_)
                                               )";
}
// https://patorjk.com/software/taag/#p=display&h=0&v=0&f=Small&t=You%20win!

#endif