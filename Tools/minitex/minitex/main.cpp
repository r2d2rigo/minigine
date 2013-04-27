#include <iostream>
#include <fstream>
#include <libfreeimage/FreeImage.h>

using namespace std;

int main(int argc, const char * argv[])
{
#if _DEBUG || DEBUG
    #if WIN32
        char* path = "ship1.png";
    #else
        char* path = "/Users/Rodrigo/Downloads/Misc2D/ship1.png";
    #endif
#else
    if (argc < 2)
    {
        cout << "Bad usage" << endl;
    
        return -1;
    }
#endif
        
    FIBITMAP* sourceImage = FreeImage_Load(FIF_PNG, path);

    if (sourceImage == NULL)
    {
        cout << "Could not open file " << path << endl;

		return -1;
    }

	FREE_IMAGE_TYPE imageType = FreeImage_GetImageType(sourceImage);
	if (imageType != FREE_IMAGE_TYPE::FIT_BITMAP)
	{
		cout << "Only images of bitmap type are supported." << endl;

		return -1;
    }

	unsigned int imageWidth = FreeImage_GetWidth(sourceImage);
    unsigned int imageHeight = FreeImage_GetHeight(sourceImage);
	unsigned int imageBpp = FreeImage_GetBPP(sourceImage);

//    FreeImage_GetBPP(<#FIBITMAP *dib#>);
//    FreeImage_GetColorType(<#FIBITMAP *dib#>);
//    FreeImage_GetImageType(<#FIBITMAP *dib#>);
//    FreeImage_GetInfo(<#FIBITMAP *dib#>);
//    FreeImage_GetWidth(<#FIBITMAP *dib#>);
//    FreeImage_GetHeight(<#FIBITMAP *dib#>);
    BYTE* imageData = FreeImage_GetBits(sourceImage);

	ofstream outputFile;
	outputFile.open("ship1.mtx", ios::out | ios::trunc | ios::binary);

	outputFile << 'M' << 'T' << 'X';
	
	outputFile.write(reinterpret_cast<char*>(&imageWidth), sizeof(int));
	outputFile.write(reinterpret_cast<char*>(&imageHeight), sizeof(int));
	outputFile.write(reinterpret_cast<char*>(imageData), imageWidth * imageHeight * (imageBpp / 8));

	outputFile.close();
    
    FreeImage_Unload(sourceImage);
    
    return 0;
}

