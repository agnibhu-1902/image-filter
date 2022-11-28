#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    unsigned int avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Compute average
            avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            //Manipulate pixel using average
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    unsigned int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Compute rgb using sepia algorithm and check for overflow condition
            sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            //Manipulate pixel using computed rgb values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, k = width - 1; j < k; j++, k--)
        {
            //Swap start and end pixels using temporary variable
            temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][k].rgbtRed;
            image[i][k].rgbtRed = temp;
            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][k].rgbtGreen;
            image[i][k].rgbtGreen = temp;
            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][k].rgbtBlue;
            image[i][k].rgbtBlue = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    unsigned int avgRed, avgGreen, avgBlue;
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avgRed = avgGreen = avgBlue = 0;
            if (i == 0)
            {
                //Top left corner condition
                if (j == 0)
                {
                    for (int k = i; k <= i + 1; k++)
                    {
                        for (int l = j; l <= j + 1; l++)
                        {
                            //Compute sum of rgb values
                            avgRed += image[k][l].rgbtRed;
                            avgGreen += image[k][l].rgbtGreen;
                            avgBlue += image[k][l].rgbtBlue;
                        }
                    }
                    //Compute average of rgb values
                    avgRed = round(avgRed / 4.0);
                    avgGreen = round(avgGreen / 4.0);
                    avgBlue = round(avgBlue / 4.0);
                    //Manipulate pixel using computed rgb values and store in temporary array
                    temp[i][j].rgbtRed = avgRed;
                    temp[i][j].rgbtGreen = avgGreen;
                    temp[i][j].rgbtBlue = avgBlue;
                }
                //Top right corner condition
                else if (j == width - 1)
                {
                    for (int k = i; k <= i + 1; k++)
                    {
                        for (int l = j - 1; l <= j; l++)
                        {
                            //Compute sum of rgb values
                            avgRed += image[k][l].rgbtRed;
                            avgGreen += image[k][l].rgbtGreen;
                            avgBlue += image[k][l].rgbtBlue;
                        }
                    }
                    //Compute average of rgb values
                    avgRed = round(avgRed / 4.0);
                    avgGreen = round(avgGreen / 4.0);
                    avgBlue = round(avgBlue / 4.0);
                    //Manipulate pixel using computed rgb values and store in temporary array
                    temp[i][j].rgbtRed = avgRed;
                    temp[i][j].rgbtGreen = avgGreen;
                    temp[i][j].rgbtBlue = avgBlue;
                }
                //Top edge condition
                else
                {
                    for (int k = i; k <= i + 1; k++)
                    {
                        for (int l = j - 1; l <= j + 1; l++)
                        {
                            //Compute sum of rgb values
                            avgRed += image[k][l].rgbtRed;
                            avgGreen += image[k][l].rgbtGreen;
                            avgBlue += image[k][l].rgbtBlue;
                        }
                    }
                    //Compute average of rgb values
                    avgRed = round(avgRed / 6.0);
                    avgGreen = round(avgGreen / 6.0);
                    avgBlue = round(avgBlue / 6.0);
                    //Manipulate pixel using computed rgb values and store in temporary array
                    temp[i][j].rgbtRed = avgRed;
                    temp[i][j].rgbtGreen = avgGreen;
                    temp[i][j].rgbtBlue = avgBlue;
                }
            }
            else if (i == height - 1)
            {
                //Bottom left corner condition
                if (j == 0)
                {
                    for (int k = i - 1; k <= i; k++)
                    {
                        for (int l = j; l <= j + 1; l++)
                        {
                            //Compute sum of rgb values
                            avgRed += image[k][l].rgbtRed;
                            avgGreen += image[k][l].rgbtGreen;
                            avgBlue += image[k][l].rgbtBlue;
                        }
                    }
                    //Compute average of rgb values
                    avgRed = round(avgRed / 4.0);
                    avgGreen = round(avgGreen / 4.0);
                    avgBlue = round(avgBlue / 4.0);
                    //Manipulate pixel using computed rgb values and store in temporary array
                    temp[i][j].rgbtRed = avgRed;
                    temp[i][j].rgbtGreen = avgGreen;
                    temp[i][j].rgbtBlue = avgBlue;
                }
                //Bottom right corner condition
                else if (j == width - 1)
                {
                    for (int k = i - 1; k <= i; k++)
                    {
                        for (int l = j - 1; l <= j; l++)
                        {
                            //Compute sum of rgb values
                            avgRed += image[k][l].rgbtRed;
                            avgGreen += image[k][l].rgbtGreen;
                            avgBlue += image[k][l].rgbtBlue;
                        }
                    }
                    //Compute average of rgb values
                    avgRed = round(avgRed / 4.0);
                    avgGreen = round(avgGreen / 4.0);
                    avgBlue = round(avgBlue / 4.0);
                    //Manipulate pixel using computed rgb values and store in temporary array
                    temp[i][j].rgbtRed = avgRed;
                    temp[i][j].rgbtGreen = avgGreen;
                    temp[i][j].rgbtBlue = avgBlue;
                }
                //Bottom edge condition
                else
                {
                    for (int k = i - 1; k <= i; k++)
                    {
                        for (int l = j - 1; l <= j + 1; l++)
                        {
                            //Compute sum of rgb values
                            avgRed += image[k][l].rgbtRed;
                            avgGreen += image[k][l].rgbtGreen;
                            avgBlue += image[k][l].rgbtBlue;
                        }
                    }
                    //Compute average of rgb values
                    avgRed = round(avgRed / 6.0);
                    avgGreen = round(avgGreen / 6.0);
                    avgBlue = round(avgBlue / 6.0);
                    //Manipulate pixel using computed rgb values and store in temporary array
                    temp[i][j].rgbtRed = avgRed;
                    temp[i][j].rgbtGreen = avgGreen;
                    temp[i][j].rgbtBlue = avgBlue;
                }
            }
            else
            {
                //Left edge condition
                if (j == 0)
                {
                    for (int k = i - 1; k <= i + 1; k++)
                    {
                        for (int l = j; l <= j + 1; l++)
                        {
                            //Compute sum of rgb values
                            avgRed += image[k][l].rgbtRed;
                            avgGreen += image[k][l].rgbtGreen;
                            avgBlue += image[k][l].rgbtBlue;
                        }
                    }
                    //Compute average of rgb values
                    avgRed = round(avgRed / 6.0);
                    avgGreen = round(avgGreen / 6.0);
                    avgBlue = round(avgBlue / 6.0);
                    //Manipulate pixel using computed rgb values and store in temporary array
                    temp[i][j].rgbtRed = avgRed;
                    temp[i][j].rgbtGreen = avgGreen;
                    temp[i][j].rgbtBlue = avgBlue;
                }
                //Right edge condition
                else if (j == width - 1)
                {
                    for (int k = i - 1; k <= i + 1; k++)
                    {
                        for (int l = j - 1; l <= j; l++)
                        {
                            //Compute sum of rgb values
                            avgRed += image[k][l].rgbtRed;
                            avgGreen += image[k][l].rgbtGreen;
                            avgBlue += image[k][l].rgbtBlue;
                        }
                    }
                    //Compute average of rgb values
                    avgRed = round(avgRed / 6.0);
                    avgGreen = round(avgGreen / 6.0);
                    avgBlue = round(avgBlue / 6.0);
                    //Manipulate pixel using computed rgb values and store in temporary array
                    temp[i][j].rgbtRed = avgRed;
                    temp[i][j].rgbtGreen = avgGreen;
                    temp[i][j].rgbtBlue = avgBlue;
                }
                //Middle condition
                else
                {
                    for (int k = i - 1; k <= i + 1; k++)
                    {
                        for (int l = j - 1; l <= j + 1; l++)
                        {
                            //Compute sum of rgb values
                            avgRed += image[k][l].rgbtRed;
                            avgGreen += image[k][l].rgbtGreen;
                            avgBlue += image[k][l].rgbtBlue;
                        }
                    }
                    //Compute average of rgb values
                    avgRed = round(avgRed / 9.0);
                    avgGreen = round(avgGreen / 9.0);
                    avgBlue = round(avgBlue / 9.0);
                    //Manipulate pixel using computed rgb values and store in temporary array
                    temp[i][j].rgbtRed = avgRed;
                    temp[i][j].rgbtGreen = avgGreen;
                    temp[i][j].rgbtBlue = avgBlue;
                }
            }
        }
    }
    //Copy contents from temporary array to original array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
