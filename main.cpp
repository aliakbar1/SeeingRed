#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>

using namespace std;

//argc - number of arguments in command
//argv - each argument word, stored in an array
int main(int argc, char* argv[])
{

        Bitmap image;        
        string filename;
        filename=argv[1];
        cout << argv[1] << endl;



        if(argc==2)       
        {

            image.open(filename);
            if(image.isImage()!=true)
            {
                cout<<  "Image file must be a bitmap with 24-bit color depth.\n";
            }
            else 
            {
                vector <vector <Pixel> > imagePixels = image.toPixelMatrix();
                cout<<"width"<<imagePixels.size()<<"height"<<imagePixels[0].size()<<endl;

                for (int r = 0; r<imagePixels.size() ; r++)
                {
                        for(int c=0; c<imagePixels[0].size(); c++)
                        {

                        Pixel color;
                         color=imagePixels[r][c];
                         color.green = 0;
                         color.blue = 0;
                        imagePixels[r][c] = color;



                        }

                }
image.fromPixelMatrix( imagePixels );
image.save("redness.bmp");
            }

        }
        else
        {"Please specify one image file!\n";}

        return 0;
}


