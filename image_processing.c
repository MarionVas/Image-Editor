#include <stdio.h>

/*
 * Read an image from the standard input and set the red value of each pixel to
 * zero.
 */
void remove_red()
{
  int R;
  int G;
  int B;
  int column;
  int row;
  int colour_range;
  char* type;
  int column_count = 0;
  scanf("%s %d %d %d", &type, &column, &row, &colour_range);
  printf("%s \n%d \n%d \n%d\n", &type, column, row, colour_range);
  while (scanf("%d %d %d", &R, &G, &B) != EOF)
  {
  	if (column_count == column)
  	{
  		printf("\n");
  		column_count = 0;
  	}
  	printf("%d %d %d\t", 0, G, B);
  	column_count++;
  }
}

/*
 * Read an image from the standard input and convert it from colour to black and white.
 */
void convert_to_black_and_white()
{
  int R;
  int G;
  int B;
  int avg;
  int column;
  int row;
  int colour_range;
  char* type;
  int column_count = 0;
  scanf("%s %d %d %d", &type, &column, &row, &colour_range);
  printf("%s \n%d \n%d \n%d\n", &type, column, row, colour_range);
  while (scanf("%d %d %d", &R, &G, &B) != EOF)
  {
    avg = (R + G + B) / 3;
    if (column_count == column)
    {
      printf("\n");
      column_count = 0;
    }
    printf("%d %d %d\t", avg, avg, avg);
    column_count++;
  }

}

/*
 * Read an image from the standard input and convert it to a square image.
 */
void instagram_square()
{
 	printf("instagram_square\n");
}

