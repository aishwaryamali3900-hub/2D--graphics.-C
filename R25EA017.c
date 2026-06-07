#include<stdio.h>
#define rows 30
#define column 30
char canvas[rows][columns];

void initializeCanvas()
{
  int i,j;
for(i=0;i<rows;i++)
{
for(j=0;j<rows;j++)
{
canvas[i][j]='_';
}
}
}

void diplayCanvas()
{
  int i,j;
for(i=0;i<rows;i++)
{
for(j=0;j<columns;j++)
{
printf("%c",canvas[i][j]);
}
printf("\n");
}
}

void drawRectangle(int row,int col,int height,int width)
{
  int i;
for(i=col;i<col+width;i++)
{
canvas[row][i]='*';
canvas[row+height-1][i]='*';
}
for(i=row;i<row+height;i++)
{
canvas[i][col]='*';
canvas[i][col+width-1]='*';
}
}

void drawLine(int row1,int col1,int row2,int col2)
{
  int i,start,end;
if(row1==row2)
{
if(col1<col2)
{
start=col1;
end=col2;
}
else
{
start=col2;
end=col1;
}
for(i=start;i<=end;i++)
canvas[row1][i]='*';
}
else if(col1==col2)
{
if(row1<row2)
{
start=row1;
end=row2;
}
else
{
start=row2;
end=row1;
}
for(i=start;i<=end;i++)
  canvas[i][col1]='*';
}
}

void drawTriangle(int row,int col,int height)
{
  int i;
for(i=0;i<height;i++)
{
canvas[row+i][col-i]='*';
canvas[row+i][col-i]='*';
}
for(i=col-height+1;i<=col+height-1;i++)
{
canvas[row+height-1][i]='*';
}
}

void drawCircle(int xc,int yc,int r)
{
  int x,y,d;
for(y=0;y<rows;y++)
{
for(x=0;x<columns;x++)
{
d=(x-xc)*(x-xc)+(y-yc)*(y-yc);
if(d<r*r)
{
canvas[y][x]='*';
}
}
}
}

void deleteArea(int row,int col,int height,int width)
{
  int i,j;
for(i=row;i<row+height;i++)
{
for(j=col;j<col+width;j++)
{
canvas[i][j]='_';
}
}
}

void deleteCircle(int xc,int yc,int r)
{
  int x,y;
for(y=0;y<rows;y++)
{
for(x=0;x<columns;x++)
{
if((x-xc)*(x-xc)+(y-yc)*(y-yc)<=r*r)
{
canvas[y][x]='_';
}
}
}
}



  













