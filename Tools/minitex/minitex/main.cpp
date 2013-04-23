#include <stdio.h>
#include <libfreeimage/FreeImage.h>

int main(int argc, const char * argv[])
{
    char* path = "/Users/Rodrigo/Downloads/Misc2D/ship1.png";
//    if (argc < 2)
//    {
//        printf("Bad usage");
    
//        return -1;
//    }
        
    FIBITMAP* sourceImage = FreeImage_Load(FIF_PNG, path);

//    FreeImage_GetBPP(<#FIBITMAP *dib#>);
//    FreeImage_GetColorType(<#FIBITMAP *dib#>);
//    FreeImage_GetImageType(<#FIBITMAP *dib#>);
//    FreeImage_GetInfo(<#FIBITMAP *dib#>);
//    FreeImage_GetWidth(<#FIBITMAP *dib#>);
//    FreeImage_GetHeight(<#FIBITMAP *dib#>);
    BYTE* imageData = FreeImage_GetBits(sourceImage);
    
    FreeImage_Unload(sourceImage);
    
    return 0;
}

