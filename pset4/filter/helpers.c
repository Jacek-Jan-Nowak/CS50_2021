#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    // Calculate the average pixel value.
    // Set each color value to the average value.
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // calculate each new color value using the Sepia formula
    // sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    // sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    // sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    // it must be rounded int and if value is more than 255 then it needs to be capped
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

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
    RGBTRIPLE buffer_row[width];
    for (int i = 0; i < height; i++)
    {
        int k = 0;
        for (int j = width - 1; j >= 0; j--)
        {
            buffer_row[k] = image[i][j];
            k++;
        }
        for (int j = 0; j < width; j++)
        {
            image[i][j] = buffer_row[j];
        }
    }
    // rows stays same
    // for each row swap pixels horizontally
    // be aware if there is odd or even number of pixels in the row
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //
    RGBTRIPLE buffer[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int averageRed = 0;
            int averageGreen = 0;
            int averageBlue = 0;
            float counter = 0.00;
            for (int h = (i - 1); h <= (i + 1); h++)
            {
                for (int w = (j - 1); w <= (j + 1); w++)
                {
                    if (h >= 0 & h <= (height - 1) & w >= 0 & (w <= width - 1))
                    {
                        averageRed += image[h][w].rgbtRed;
                        averageGreen += image[h][w].rgbtGreen;
                        averageBlue += image[h][w].rgbtBlue;
                        counter++;
                    }
                }
            }
            averageRed = round(averageRed / counter);
            averageGreen = round(averageGreen / counter);
            averageBlue = round(averageBlue / counter);

            buffer[i][j].rgbtRed = averageRed;
            buffer[i][j].rgbtGreen = averageGreen;
            buffer[i][j].rgbtBlue = averageBlue;
            //  int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            //  image[i][j].rgbtRed = average;
            //  image[i][j].rgbtGreen = average;
            //  image[i][j].rgbtBlue = average;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = buffer[i][j].rgbtRed;
            image[i][j].rgbtGreen = buffer[i][j].rgbtGreen;
            image[i][j].rgbtBlue = buffer[i][j].rgbtBlue;
        }
    }
    return;
}
