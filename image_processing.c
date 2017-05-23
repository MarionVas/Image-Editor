#include <stdio.h>

int R;
int G;
int B;  
int column;
int row;
int ignore_value;
int ignore_value_temp;
int colour_range;
char type;
int column_count = 0;
int row_count = 0;
/*
 * Read an image from the standard input and set the red value of each pixel to
 * zero.
 */
void remove_red()
{
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
  int avg;
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
  scanf("%s %d %d %d", &type, &column, &row, &colour_range);

  int smaller_dim = row > column ? column : row;
  ignore_value =  row > column ? 0 : column - row;
  ignore_value_temp = ignore_value;
  printf("%s \n%d \n%d \n%d\n", &type, smaller_dim, smaller_dim, colour_range);

  while (scanf("%d %d %d", &R, &G, &B) != EOF)
  {
    if (row_count < smaller_dim){
      if (column_count < smaller_dim)
      {
        printf("%d %d %d\t", R, G, B);
        column_count++;
      }
      else 
      {
        ignore_value_temp--;
      }

      if (ignore_value_temp <= 0 && column_count == smaller_dim)
      {
        ignore_value_temp = ignore_value;
        column_count = 0;
        printf("\n");
        row_count++;
      }
  
    }
  }
}

