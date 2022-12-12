 #include <stdio.h>
 #include <stdlib.h> /* for ISO C Random Number Functions */
 #include <math.h>
 /*  gives sign of number */
 double sign(double d)
 {
       if (d<0)
       {return -1.0;}
       else {return 1.0;};
 };
 /* ----------------------*/
 int main()
 {   
    const double Cx=0.0,Cy=1.0;
     /* screen coordinate = coordinate of pixels */      
    int iX, iY, 
        iXmin=0, iXmax=2000,
        iYmin=0, iYmax=2000,
        iWidth=iXmax-iXmin+1,
        iHeight=iYmax-iYmin+1,
        /* number of bytes = number of pixels of image * number of bytes of color */
        iLength=iWidth*iHeight*3,/* 3 bytes of color  */
        index; /* of array */
   int iXinc, iYinc;     
   /* world ( double) coordinate = parameter plane*/
        const double ZxMin=-2.5;
        const double ZxMax=2.5;
        const double ZyMin=-2.5;
        const double ZyMax=2.5;
        /* */
        double PixelWidth=(ZxMax-ZxMin)/iWidth;
        double PixelHeight=(ZyMax-ZyMin)/iHeight;
        double Zx, Zy,    /* Z=Zx+Zy*i   */
               NewZx, NewZy,
               DeltaX, DeltaY,
               SqrtDeltaX, SqrtDeltaY,
               AlphaX, AlphaY,
               BetaX,BetaY; /* repelling fixed point Beta */
         /*  */
        int Iteration,
            IterationMax=100000000;
     /* PPM file */
    FILE * fp;
    char *filename="julia1.ppm";
    char *comment="# this is julia set for c=i ";/* comment should start with # */
    const int MaxColorComponentValue=255;/* color component ( R or G or B) is coded from 0 to 255 */
     /* dynamic 1D array for 24-bit color values */    
    unsigned char *array;
  /*  ---------  find repelling fixed point ---------------------------------*/
   /* Delta=1-4*c */
   DeltaX=1-4*Cx;
   DeltaY=-4*Cy;
   /* SqrtDelta = sqrt(Delta) */
   /* sqrt of complex number algorithm from Peitgen, Jurgens, Saupe: Fractals for the classroom */
   if (DeltaX>0)
   {
    SqrtDeltaX=sqrt((DeltaX+sqrt(DeltaX*DeltaX+DeltaY*DeltaY))/2);
    SqrtDeltaY=DeltaY/(2*SqrtDeltaX);        
    }
    else /* DeltaX <= 0 */
    {
         if (DeltaX<0)
         {
          SqrtDeltaY=sign(DeltaY)*sqrt((-DeltaX+sqrt(DeltaX*DeltaX+DeltaY*DeltaY))/2);
          SqrtDeltaX=DeltaY/(2*SqrtDeltaY);        
          }
          else /* DeltaX=0 */
          {
           SqrtDeltaX=sqrt(fabs(DeltaY)/2);
           if (SqrtDeltaX>0) SqrtDeltaY=DeltaY/(2*SqrtDeltaX);
                        else SqrtDeltaY=0;    
                }
    };
   /* Beta=(1-sqrt(delta))/2 */
   BetaX=0.5+SqrtDeltaX/2;
   BetaY=SqrtDeltaY/2;
   /* Alpha=(1+sqrt(delta))/2 */
   AlphaX=0.5-SqrtDeltaX/2;
   AlphaY=-SqrtDeltaY/2;
   printf(" Cx= %f\n",Cx);
   printf(" Cy= %f\n",Cy); 
   printf(" Beta= %f\n",BetaX);
   printf(" BetaY= %f\n",BetaY);
   printf(" AlphaX= %f\n",AlphaX);
   printf(" AlphaY= %f\n",AlphaY);
   /* initial value of orbit Z=Z0 is repelling fixed point */
   Zy=BetaY; /*  */
   Zx=BetaX; 
   /*-------------------------------------------------------------------*/
    array = malloc( iLength * sizeof(unsigned char) );
    if (array == NULL)
    {
      fprintf(stderr,"Could not allocate memory");
      getchar();
      return 1;
    }
    else 
    {         
      /* fill the data array with white points */       
      for(index=0;index<iLength-1;++index) array[index]=255;
   /* ---------------------------------------------------------------*/
  for (Iteration=0;Iteration<IterationMax;Iteration++)
            {
                /* Zn*Zn=Z(n+1)-c */
                Zx=Zx-Cx;
                Zy=Zy-Cy;
                /* sqrt of complex number algorithm from Peitgen, Jurgens, Saupe: Fractals for the classroom */
                if (Zx>0)
                {
                 NewZx=sqrt((Zx+sqrt(Zx*Zx+Zy*Zy))/2);
                 NewZy=Zy/(2*NewZx);        
                 }
                 else /* ZX <= 0 */
                 {
                  if (Zx<0)
                     {
                      NewZy=sign(Zy)*sqrt((-Zx+sqrt(Zx*Zx+Zy*Zy))/2);
                      NewZx=Zy/(2*NewZy);        
                      }
                      else /* Zx=0 */
                      {
                       NewZx=sqrt(fabs(Zy)/2);
                       if (NewZx>0) NewZy=Zy/(2*NewZx);
                          else NewZy=0;    
                      }
                 };
              if (rand()<(RAND_MAX/2))
              {   
                  Zx=NewZx;
                  Zy=NewZy; 
                  }
              else {Zx=-NewZx;
                  Zy=-NewZy; }
              /* translate from world to screen coordinate */
              iX=(Zx-ZxMin)/PixelWidth;
              iY=(Zy-ZyMin)/PixelHeight; /*  */
              /* plot  pixel  */
              array[((iYmax-iY-1)*iXmax+iX)*3]=0;
              array[((iYmax-iY-1)*iXmax+iX)*3+1]=0;
              array[((iYmax-iY-1)*iXmax+iX)*3+2]=0; 
            };           
      /* write the whole data array to ppm file in one step */      
      /*create new file,give it a name and open it in binary mode  */
      fp= fopen(filename,"wb"); /* b -  binary mode */
      if (fp == NULL){ fprintf(stderr,"file error"); }
            else
            {
            /*write ASCII header to the file*/
            fprintf(fp,"P6\n %s\n %d\n %d\n %d\n",comment,iXmax,iYmax,MaxColorComponentValue);
            /*write image data bytes to the file*/
            fwrite(array,iLength ,1,fp);
            fclose(fp);
            fprintf(stderr,"file saved");
            getchar();
            }
      free(array);
      return 0;
    } /* if (array ..  else ... */
 }
