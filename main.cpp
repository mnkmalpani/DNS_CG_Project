#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>
#include<unistd.h>
using namespace std;

int choice=0,count=0,i,count1=0,count2=-1,h=0;
volatile int a[1]={1};


char homepage[]={"Homepage"};
char text1[]={"Department of Computer Science and Engineering"};
char text2[]={"PESIT BANGALORE SOUTH CAMPUS"};
char text3[]={"Hosur Road, Bengaluru -560100"};
char text4[]={"www.google.com"};
char text5[]={"Press spacebar to continue:"};
char text6[]={"Press Esc to exit."};
char text7[]={"www.pes.edu"};
char text8[]={"Error 404 Page Not Found!!"};
char text9[]={"Local DNS"};
char text10[]={"Root DNS"};
char text11[]={".com DNS"};
char text12[]={"google.com DNS"};
char text13[]={".edu DNS"};
char text14[]={"pes.edu DNS"};
char text15[]={"Menu:"};
char text16[]={"1 ==> www.google.com"};
char text17[]={"2 ==> www.pes.edu"};
char text18[]={"Enter your choice(1/2): "};
char text19[]={"v.bmp"};
char text20[]={"p.bmp"};
char text21[]={"g.bmp"};
char text22[]={"pesse.bmp"};
char text23[]={"404.bmp"};
char text24[]={"1"};
char text25[]={"2"};
char text26[]={"DOMAIN NAME SYSTEM (DNS)"};
char text27[]={"A Mini Project on:"};
char text28[]={"Submitted by:"};
char text29[]={"MANISH AGARWAL          (1PE13CS084)"};
char text30[]={"MAYANK MALPANI           (1PE13CS085)"};
char text31[]={"Under the guidance of:"};
char text32[]={"Mrs. Shubha Raj K B"};
char text33[]={"Assistant Professor"};
char text34[]={"PESIT BSC, Bengaluru."};
char text35[]={"Computer Graphics and Visualization Lab (10CSL67)"};
char text36[]={"Press r to try again:"};


int packet[4][2]={{25,250},{35,250},{35,260},{25,260}};//browser to local dns
int resmatrix1[4][2]={{80,55},{90,55},{90,65},{80,65}};//local dns to root dns
int resmatrix2[4][2]={{190,130},{200,130},{200,140},{190,140}};//root dns to midway down
int resmatrix3[4][2]={{240,145},{250,145},{250,155},{240,155}};//midway down to midway up
int resmatrix4[4][2]={{252,305},{262,305},{262,315},{252,315}};//midway up to .com dns
int resmatrix5[4][2]={{340,305},{350,305},{350,315},{340,315}};//.com dns to a.com dns
int resmatrix6[4][2]={{190,40},{200,40},{200,50},{190,50}};//root dns to .edu dns
int resmatrix7[4][2]={{340,40},{350,40},{350,50},{340,50}};//.edu dns to pes.edu dns


int resmatrix8[14][2]={{390,370},{400,370},{400,380},{390,380},//black packet
                                {400,375},{405,375},//middle line
                                {405,370},{415,370},{415,390},{405,390},//box
                                {407,375},{413,375},//line1
                                {407,385},{413,385}};//line2        //a.com to .com dns

int resmatrix9[14][2]={{270,370},{280,370},{280,380},{270,380},//black packet
                                {280,375},{285,375},//middle line
                                {285,370},{295,370},{295,390},{285,390},//box
                                {287,375},{293,375},//line1
                                {287,385},{293,385}};//line2        //.com to midway up

int resmatrix10[14][2]={{220,350},{230,350},{230,360},{220,360},//black packet
                                {220,355},{215,355},//middle line
                                {215,350},{205,350},{205,370},{215,370},//box
                                {213,355},{207,355},//line1
                                {213,365},{207,365}};//line2        //midway up to down

int resmatrix11[14][2]={{200,175},{210,175},{210,185},{200,185},//black packet
                                {210,180},{215,180},//middle line
                                {215,175},{225,175},{225,195},{215,195},//box
                                {217,180},{223,180},//line1
                                {217,190},{223,190}};//line2        //midway down to root

int resmatrix12[14][2]={{120,120},{130,120},{130,130},{120,130},//black packet
                                {130,125},{135,125},//middle line
                                {135,120},{145,120},{145,140},{135,140},//box
                                {137,125},{142,125},//line1
                                {137,135},{142,135}};//line2        //root to local

int resmatrix13[14][2]={{55,200},{65,200},{65,210},{55,210},//black packet
                                {65,205},{70,205},//middle line
                                {70,200},{80,200},{80,220},{70,220},//box
                                {72,205},{78,205},//line1
                                {72,215},{78,215}};//line2        //local to browser

int resmatrix14[14][2]={{390,90},{400,90},{400,100},{390,100},//black packet
                                {400,95},{405,95},//middle line
                                {405,90},{415,90},{415,110},{405,110},//box
                                {407,95},{413,95},//line1
                                {407,105},{413,105}};//line2        //pes.edu to .edu

int resmatrix15[14][2]={{270,90},{280,90},{280,100},{270,100},//black packet
                                {280,95},{285,95},//middle line
                                {285,90},{295,90},{295,110},{285,110},//box
                                {287,95},{293,95},//line1
                                {287,105},{293,105}};//line2        //.edu to root



struct BMPImage
{
    int   width;
    int   height;
    char *data;
};


class glTexture
{
    public:
        glTexture();
        void loadTextureInfo(char * bmpFile, int PicID);
        void getBitmapImageData(char *pFileName, BMPImage *pImage);
        void SetActive(int PicID);
    private:
        GLuint g_textureID;
        BMPImage textureImage[10];
};


glTexture hTexture;


glTexture::glTexture()
{
}


void glTexture::SetActive(int PicID)
{
    glGenTextures( 1, &g_textureID );
	glBindTexture( GL_TEXTURE_2D, g_textureID );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

	glTexImage2D( GL_TEXTURE_2D, 0, 3, textureImage[PicID].width, textureImage[PicID].height,
	               0, GL_RGB, GL_UNSIGNED_BYTE, textureImage[PicID].data );
    return;
}


void glTexture::loadTextureInfo(char * bmpFile, int PicID)
{
    getBitmapImageData( bmpFile, &textureImage[PicID] );
    return;
}


void glTexture::getBitmapImageData( char *pFileName, BMPImage *pImage )
{
    FILE *pFile = NULL;
    unsigned short nNumPlanes;
    unsigned short nNumBPP;
	int i;

    if( (pFile = fopen(pFileName, "rb") ) == NULL )
		printf("ERROR: getBitmapImageData - %s not found\n",pFileName);

    // Seek forward to width and height info
    fseek( pFile, 18, SEEK_CUR );
    if( (i = fread(&pImage->width, 4, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read width from %s.\n", pFileName);

    if( (i = fread(&pImage->height, 4, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read height from %s.\n", pFileName);

    if( (fread(&nNumPlanes, 2, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read plane count from %s.\n", pFileName);

    if( nNumPlanes != 1 )
		printf( "ERROR: getBitmapImageData - Plane count from %s is not 1: %u\n", pFileName, nNumPlanes );

    if( (i = fread(&nNumBPP, 2, 1, pFile)) != 1 )
		printf( "ERROR: getBitmapImageData - Couldn't read BPP from %s.\n", pFileName );

    if( nNumBPP != 24 )
		printf( "ERROR: getBitmapImageData - BPP from %s is not 24: %u\n", pFileName, nNumBPP );

    // Seek forward to image data
    fseek( pFile, 24, SEEK_CUR );

	// Calculate the image's total size in bytes. Note how we multiply the
	// result of (width * height) by 3. This is becuase a 24 bit color BMP
	// file will give you 3 bytes per pixel.
    int nTotalImagesize = (pImage->width * pImage->height) * 3;
    pImage->data = (char*) malloc( nTotalImagesize );

    if( (i = fread(pImage->data, nTotalImagesize, 1, pFile) ) != 1 )
		printf("ERROR: getBitmapImageData - Couldn't read image data from %s.\n", pFileName);

	// Finally, rearrange BGR to RGB
	char charTemp;

    for( i = 0; i < nTotalImagesize; i += 3 )
	{
		charTemp = pImage->data[i];
		pImage->data[i] = pImage->data[i+2];
		pImage->data[i+2] = charTemp;
    }
    return;
}


void draw1( )
{
    //browser box
    glLineWidth(3.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(10.0,490.0);
        glVertex2f(200.0,490.0);
        glVertex2f(200.0,250.0);
        glVertex2f(10.0,250.0);
    glEnd();
    glFlush();

    //url box
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(15.0,480.0);
        glVertex2f(195.0,480.0);
        glVertex2f(195.0,460.0);
        glVertex2f(15.0,460.0);
    glEnd();
    glFlush();

    //url small box
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex2f(45.0,480.0);
        glVertex2f(45.0,460.0);
    glEnd();
    glFlush();

    //home symbol square
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
        glVertex2f(95.0,420.0);
        glVertex2f(115.0,420.0);
        glVertex2f(115.0,440.0);
        glVertex2f(95.0,440.0);
    glEnd();
    glFlush();

    //home symbol triangle
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_TRIANGLES);
        glVertex2f(120.0,440.0);
        glVertex2f(105.0,455.0);
        glVertex2f(90.0,440.0);
    glEnd();
    glFlush();

    //printing homepage
    int i;
	glRasterPos2f(88.0, 410.0);
	for (i=0; homepage[i] != '\0'; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, homepage[i]);
	}

	//printing url
	glRasterPos2f(20.0, 464.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'U');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'R');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'L');
	return;
}


void drawserver(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float lx1, float ly1, float lx2, float ly2)
{
    //drawing server outer box
    glLineWidth(2.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glVertex2f(x4,y4);
    glEnd();
    glFlush();

    //drawing server name line
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
        glVertex2f(lx1,ly1);
        glVertex2f(lx2,ly2);
    glEnd();
    glFlush();
    return;
}


void servername(float rx1, float ry1, char str[])   //func used to print all text
{
     int i;
	glRasterPos2f(rx1,ry1);
	for (i=0; str[i] != '\0'; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
	}
	return;
}


void drawpathgreen()
{
    //drawing green lines connecting the browser & servers
    glColor3f(0.0,1.0,0.0);
    glLineWidth(5.0);
    glBegin(GL_LINES);

    //browser to local dns
    glVertex2f(30.0,250.0);
    glVertex2f(30.0,200.0);


    //local dns to root dns
    glVertex2f(90.0,60.0);
    glVertex2f(120.0,60.0);

    //root dns to midway down
    glVertex2f(200.0,135.0);
    glVertex2f(245.0,135.0);

    //midway down to midway up
    glVertex2f(245.0,135.0);
    glVertex2f(245.0,310.0);

    //midway up to .com dns
    glVertex2f(245.0,310.0);
    glVertex2f(270.0,310.0);


    //.com dns to a.com dns
    glVertex2f(350.0,310.0);
    glVertex2f(390.0,310.0);


    //root dns to .edu dns
    glVertex2f(200.0,45.0);
    glVertex2f(270.0,45.0);


    //.edu dns to pes.edu dns
    glVertex2f(350.0,45.0);
    glVertex2f(390.0,45.0);

    glEnd();
    glFlush();
    glLineWidth(2.0);
    return;
}


void drawpathred()
{
    //drawing red lines connecting the browser & servers
    glColor3f(1.0,0.0,0.0);
    glLineWidth(5.0);
    glBegin(GL_LINES);

    //browser to local dns
    glVertex2f(60.0,250.0);
    glVertex2f(60.0,200.0);


     //local dns to root dns
    glVertex2f(90.0,120.0);
    glVertex2f(120.0,120.0);


    //root dns to midway down
    glVertex2f(200.0,175.0);
    glVertex2f(225.0,175.0);

    //midway down to midway up
    glVertex2f(225.0,175.0);
    glVertex2f(225.0,370.0);

    //midway up to .com dns
    glVertex2f(225.0,370.0);
    glVertex2f(270.0,370.0);


    //.com dns to a.com dns
    glVertex2f(350.0,370.0);
    glVertex2f(390.0,370.0);


    //root dns to .edu dns
    glVertex2f(200.0,90.0);
    glVertex2f(270.0,90.0);


     //.edu dns to pes.edu dns
    glVertex2f(350.0,90.0);
    glVertex2f(390.0,90.0);

    glEnd();
    glFlush();
    glLineWidth(2.0);
    return;
}


void servercontent()
{
    //a.com dns
    glColor3f(1.0,0.5490,0.0);//orange
    glBegin(GL_QUADS);
        glVertex2f(410.0,340.0);
        glVertex2f(450.0,340.0);
        glVertex2f(450.0,350.0);
        glVertex2f(410.0,350.0);
    glEnd();
    glFlush();

    //.com dns
    glColor3f(0.6471,0.1647,0.1647);//brown
    glBegin(GL_QUADS);
        glVertex2f(290.0,350.0);
        glVertex2f(330.0,350.0);
        glVertex2f(330.0,355.0);
        glVertex2f(290.0,355.0);
    glEnd();
    glFlush();

    //pes.edu dns
    glColor3f(0.5804,0.0,0.8275);//purple
    glBegin(GL_QUADS);
        glVertex2f(410.0,140.0);
        glVertex2f(450.0,140.0);
        glVertex2f(450.0,150.0);
        glVertex2f(410.0,150.0);
    glEnd();
    glFlush();

    //.edu dns
    glColor3f(0.1176,0.5647,1.0);//blue
    glBegin(GL_QUADS);
        glVertex2f(290.0,150.0);
        glVertex2f(330.0,150.0);
        glVertex2f(330.0,155.0);
        glVertex2f(290.0,155.0);
    glEnd();
    glFlush();
    return;
}


void movepacketvertical(int a[4][2],int c,int down,int up)
{
    //draws packet from browser to local dns
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2d(a[0][0],a[0][1]);
        glVertex2d(a[1][0],a[1][1]);
        glVertex2d(a[2][0],a[2][1]);
        glVertex2d(a[3][0],a[3][1]);
    glEnd();
    glFlush();

    while(c<10)
    {
        glPushMatrix();
        if(down==1 && up==0)
            glTranslatef(0.0,-18.0,0.0);
        else if(up==1 && down==0)
            glTranslatef(0.0,+18.0,0.0);
        c++;
        for(i=0;i<100000000;i++);
            movepacketvertical(a,c,down,up);//recursion
        glPopMatrix();
        return;
    }
    return;
}


void movereturnpacketvertical(int a[4][2],int c,int down,int up,int choice)
{
    //draws packet from browser to local dns
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2d(a[0][0],a[0][1]);
        glVertex2d(a[1][0],a[1][1]);
        glVertex2d(a[2][0],a[2][1]);
        glVertex2d(a[3][0],a[3][1]);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
        glVertex2d(a[4][0],a[4][1]);
        glVertex2d(a[5][0],a[5][1]);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2d(a[6][0],a[6][1]);
        glVertex2d(a[7][0],a[7][1]);
        glVertex2d(a[8][0],a[8][1]);
        glVertex2d(a[9][0],a[9][1]);
    glEnd();

    glLineWidth(8.0);
    glBegin(GL_LINES);

    if(choice==1)
        glColor3f(1.0,0.5490,0.0);

    else if(choice==2)
        glColor3f(0.5804,0.0,0.8275);//purple

    else
        glColor3f(1.0,1.0,1.0);

    glVertex2d(a[10][0],a[10][1]);
    glVertex2d(a[11][0],a[11][1]);

    if(choice==1)
        glColor3f(0.6471,0.1647,0.1647);

    else if(choice==2)
        glColor3f(0.1176,0.5647,1.0);//blue

    else
        glColor3f(1.0,1.0,1.0);

    glVertex2d(a[12][0],a[12][1]);
    glVertex2d(a[13][0],a[13][1]);
    glEnd();
    glFlush();

    while(c<10)
    {
        glPushMatrix();
        if(down==1 && up==0)
            glTranslatef(0.0,-35.0,0.0);

        else if(up==1 && down==0)
            glTranslatef(0.0,+35.0,0.0);

        c++;

        for(i=0;i<100000000;i++);
            movereturnpacketvertical(a,c,down,up,choice);//recursion

        glPopMatrix();
        return;
    }
    return;
}


void movepackethorizontal(int b[4][2], int c,int right)
{
    //draws packet from local dns to root dns
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2d(b[0][0],b[0][1]);
        glVertex2d(b[1][0],b[1][1]);
        glVertex2d(b[2][0],b[2][1]);
        glVertex2d(b[3][0],b[3][1]);
    glEnd();
    glFlush();

    while(c<2)
    {
        glPushMatrix();
        if(right==1)
            glTranslatef(+15.0,0.0,0.0);

        else
            glTranslatef(-15.0,0.0,0.0);

        c++;

        for(i=0;i<100000000;i++);
            movepackethorizontal(b,c,right);//recursion

        glPopMatrix();
        return;
    }
    return;
}


void movereturnpackethorizontal(int b[14][2], int c,int right,int choice)
{
    //draws packet from local dns to root dns
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2d(b[0][0],b[0][1]);
        glVertex2d(b[1][0],b[1][1]);
        glVertex2d(b[2][0],b[2][1]);
        glVertex2d(b[3][0],b[3][1]);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
        glVertex2d(b[4][0],b[4][1]);
        glVertex2d(b[5][0],b[5][1]);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2d(b[6][0],b[6][1]);
        glVertex2d(b[7][0],b[7][1]);
        glVertex2d(b[8][0],b[8][1]);
        glVertex2d(b[9][0],b[9][1]);
    glEnd();

    glLineWidth(8.0);
    glBegin(GL_LINES);

    if(choice==1)
        glColor3f(1.0,0.5490,0.0);

    else if(choice==2)
        glColor3f(0.5804,0.0,0.8275);//purple

    else
        glColor3f(1.0,1.0,1.0);

    glVertex2d(b[10][0],b[10][1]);
    glVertex2d(b[11][0],b[11][1]);

    if(choice==1)
        glColor3f(0.6471,0.1647,0.1647);

    else if(choice==2)
        glColor3f(0.1176,0.5647,1.0);//blue

    else
        glColor3f(1.0,1.0,1.0);

    glVertex2d(b[12][0],b[12][1]);
    glVertex2d(b[13][0],b[13][1]);
    glEnd();
    glFlush();

    while(c<2)
    {
        glPushMatrix();

        if(right==1)
            glTranslatef(+30.0,0.0,0.0);

        else
            glTranslatef(-30.0,0.0,0.0);

        c++;

        for(i=0;i<100000000;i++);
            movereturnpackethorizontal(b,c,right,choice);//recursion

        glPopMatrix();
        return;
    }
    return;
}


void img1()     //vtu logo
{
    glLoadIdentity();

    hTexture.loadTextureInfo(text19, 1);
    hTexture.SetActive(1);

    glPushMatrix();

    glBegin(GL_QUADS);
        glTexCoord2d(0.0, 0.0);glVertex2f(-0.9, -0.3);
        glTexCoord2d(0.0, 1.0);glVertex2f(-0.9, 0.5);
        glTexCoord2d(1.0, 1.0);glVertex2f(-0.4,0.5);
        glTexCoord2d(1.0, 0.0);glVertex2f(-0.4, -0.3);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
	return;
}


void img2()    //pes logo
{
    glLoadIdentity();

    hTexture.loadTextureInfo(text20, 2);
    hTexture.SetActive(2);

    glPushMatrix();

    glBegin(GL_QUADS);
        glTexCoord2d(0.0, 0.0);glVertex2f(0.4, -0.3);
        glTexCoord2d(0.0, 1.0);glVertex2f(0.4, 0.5);
        glTexCoord2d(1.0, 1.0);glVertex2f(0.9,0.5);
        glTexCoord2d(1.0, 0.0);glVertex2f(0.9, -0.3);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
	return;
}


void img3() //func to load image in browser
{
    glLoadIdentity();

    if(h==1)
    {
        hTexture.loadTextureInfo(text21, 3);
        hTexture.SetActive(3);
    }

    else if(h==2)
    {
        hTexture.loadTextureInfo(text22, 4);
        hTexture.SetActive(4);
    }

    else if(h==3)
    {
        hTexture.loadTextureInfo(text23, 5);
        hTexture.SetActive(5);
    }

    glPushMatrix();

    glBegin(GL_QUADS);
        glTexCoord2d(0.0, 0.0);glVertex2f(-0.94, 0.05);
        glTexCoord2d(0.0, 1.0);glVertex2f(-0.94, 0.83);
        glTexCoord2d(1.0,1.0);glVertex2f(-0.22,0.83);
        glTexCoord2d(1.0, 0.0);glVertex2f(-0.22, 0.05);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
	return;
}


void choice1()
{
    glColor3f(1.0,0.0,0.0);
    servername(95.0,355.0,text24);
    movepacketvertical(packet,7,1,0);//browser to local dns
    for(i=0;i<100000000;i++);
    movepackethorizontal(resmatrix1,0,1);//local to root dns
    for(i=0;i<100000000;i++);
    movepackethorizontal(resmatrix2,-1,1);//root to midway down
    for(i=0;i<100000000;i++);
    movepacketvertical(resmatrix3,1,0,1);//midway down to midway up
    for(i=0;i<100000000;i++);
    movepackethorizontal(resmatrix4,1,1);//midway up to .com dns
    for(i=0;i<100000000;i++);
    movepackethorizontal(resmatrix5,-1,1);//.com to a.com dns
    for(i=0;i<100000000;i++);


    movereturnpackethorizontal(resmatrix8,0,0,1);//a.com to .com dns
    for(i=0;i<100000000;i++);
    movereturnpackethorizontal(resmatrix9,0,0,1);//.com to midway up
    for(i=0;i<100000000;i++);
    movereturnpacketvertical(resmatrix10,6,1,0,1);//midway up to down
    for(i=0;i<100000000;i++);
    movereturnpackethorizontal(resmatrix11,2,0,1);//midway down to root
    for(i=0;i<100000000;i++);
    movereturnpackethorizontal(resmatrix12,1,0,1);//root to local
    for(i=0;i<100000000;i++);
     movereturnpacketvertical(resmatrix13,9,0,1,1);//local to browser
    for(i=0;i<100000000;i++);


    glColor3f(0.0,0.0,1.0);
    servername(55.0,465.0,text4);
    glColor3f(1.0,0.0,0.0);
    servername(250.0,480.0,text36);
    glColor3f(1.0,0.0,0.0);
    servername(250.0,465.0,text6);


    glColor3f(1.0,0.0,0.0);
    h=1;
    glColor3f(1.0,1.0,1.0);
    img3();
    glFlush();
    return;
}


void choice2()
{
    glColor3f(1.0,0.0,0.0);
    servername(95.0,355.0,text25);
    movepacketvertical(packet,7,1,0);//browser to local dns
    for(i=0;i<100000000;i++);
    movepackethorizontal(resmatrix1,0,1);//local to root dns
    for(i=0;i<100000000;i++);
    movepackethorizontal(resmatrix6,-3,1);//root to .edu dns
    for(i=0;i<100000000;i++);
    movepackethorizontal(resmatrix7,-1,1);//.edu to pes.edu
    for(i=0;i<100000000;i++);


    movereturnpackethorizontal(resmatrix14,0,0,2);//pes.edu to .edu
    for(i=0;i<100000000;i++);
    movereturnpackethorizontal(resmatrix15,-1,0,2);//.edu to root
    for(i=0;i<100000000;i++);
    movereturnpackethorizontal(resmatrix12,1,0,2);//root to local
    for(i=0;i<100000000;i++);
     movereturnpacketvertical(resmatrix13,9,0,1,2);//local to browser
    for(i=0;i<100000000;i++);


    glColor3f(0.0,0.0,1.0);
    servername(55.0,465.0,text7);
    glColor3f(1.0,0.0,0.0);
    servername(250.0,480.0,text36);
    glColor3f(1.0,0.0,0.0);
    servername(250.0,465.0,text6);


    glColor3f(1.0,0.0,0.0);
    h=2;
    glColor3f(1.0,1.0,1.0);
    img3();
    glFlush();
    return;
}


void choicedefault()
{
    movepacketvertical(packet,7,1,0);//browser to local dns
    for(i=0;i<100000000;i++);
    movepackethorizontal(resmatrix1,0,1);//local to root dns
    for(i=0;i<100000000;i++);


    movereturnpackethorizontal(resmatrix12,1,0,0);//root to local
    for(i=0;i<100000000;i++);
     movereturnpacketvertical(resmatrix13,9,0,1,0);//local to browser
    for(i=0;i<100000000;i++);


    glColor3f(0.0,0.0,1.0);
    servername(55.0,465.0,text8);
    glColor3f(1.0,0.0,0.0);
    servername(250.0,480.0,text36);
    glColor3f(1.0,0.0,0.0);
    servername(250.0,465.0,text6);


    glColor3f(1.0,1.0,1.0);
    h=3;
    img3();
    glFlush();
    return;
}


void display()
{
    if(a[0]==1)//frontpage
    {
        glLoadIdentity();
        glClearColor(1.0,0.9372,0.8353,1.0);//papaya whip
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0,0.0,1.0);
        servername(-0.3,0.9,text2);
        glColor3f(0.5,0.5,0.5);
        servername(-0.25,0.83,text3);
        glColor3f(0.0,0.0,1.0);
        servername(-0.35,0.7,text1);
        glColor3f(0.0,0.0,0.0);
        servername(-0.34,0.5,text35);
        glColor3f(0.5,0.5,0.5);
        servername(-0.15,0.3,text27);
        glColor3f(1.0,0.0,0.0);
        servername(-0.25,0.2,text26);
        glColor3f(0.5,0.5,0.5);
        servername(-0.9,-0.5,text28);
        glColor3f(0.0,0.0,1.0);
        servername(-0.9,-0.6,text29);
        glColor3f(0.0,0.0,1.0);
        servername(-0.9,-0.7,text30);
        glColor3f(0.5,0.5,0.5);
        servername(0.45,-0.5,text31);
        glColor3f(0.0,0.0,1.0);
        servername(0.45,-0.6,text32);
        glColor3f(0.0,0.0,0.0);
        servername(0.46,-0.67,text33);
        glColor3f(0.0,0.0,0.0);
        servername(0.44,-0.74,text34);
        glColor3f(0.0,0.0,0.0);
        servername(-0.2,-0.3,text5);
        glColor3f(1.0,1.0,1.0);
        img1();
        img2();
        glFlush();
        glPopMatrix();
        return;
    }

    else        //actual dns display
    {
        glClearColor(1.0,1.0,1.0,1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        draw1();
        glColor3f(1.0,1.0,1.0);
        drawserver(10.0,10.0,90.0,10.0,90.0,200.0,10.0,200.0, 10.0,180.0,90.0,180.0);
        glColor3f(0.5,0.5,0.5);
        servername(32.0,185.0,text9);
        glColor3f(1.0,1.0,1.0);
        drawserver(120.0,10.0,200.0,10.0,200.0,200.0,120.0,200.0, 120.0,180.0,200.0,180.0);
        glColor3f(0.5,0.5,0.5);
        servername(142.0,185.0,text10);
        glColor3f(1.0,1.0,1.0);
        drawserver(270.0,250.0,350.0,250.0,350.0,440.0,270.0,440.0, 270.0,420.0,350.0,420.0);
        glColor3f(0.5,0.5,0.5);
        servername(292.0,425.0,text11);
        glColor3f(1.0,1.0,1.0);
        drawserver(390.0,250.0,470.0,250.0,470.0,440.0,390.0,440.0, 390.0,420.0,470.0,420.0);
        glColor3f(0.5,0.5,0.5);
        servername(406.0,425.0,text12);
        glColor3f(1.0,1.0,1.0);
        drawserver(270.0,10.0,350.0,10.0,350.0,200.0,270.0,200.0, 270.0,180.0,350.0,180.0);
        glColor3f(0.5,0.5,0.5);
        servername(292.0,185.0,text13);
        glColor3f(1.0,1.0,1.0);
        drawserver(390.0,10.0,470.0,10.0,470.0,200.0,390.0,200.0, 390.0,180.0,470.0,180.0);
        glColor3f(0.5,0.5,0.5);
        servername(409.0,185.0,text14);
        drawpathgreen();
        drawpathred();
        servercontent();
        glColor3f(1.0,0.0,0.0);
        servername(20.0,400.0,text15);
        glColor3f(0.0,0.0,1.0);
        servername(20.0,385.0,text16);
        servername(20.0,370.0,text17);
        glColor3f(0.0,0.0,0.0);
        servername(20.0,355.0,text18);
        glFlush();
        return;
    }
}


void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,499.0,0.0,499.0);
    return;
}


void mykey(unsigned char key,int x,int y) //function to handle key presses
{
    if(key=='r' || key=='R' || key==32)  //32 is ascii for spacebar
        {
            a[0]=0;
            myinit();
            display();
        }
    if(key=='1')
        {
            choice1();
        }
    if(key=='2')
        {
            choice2();
        }
    if(key==27)
        {
            exit(0);
        }
    if(key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0')
        {
            choicedefault();
        }
}


int main(int argc,char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1600,900);
	glutInitWindowPosition(0,0);
    glutCreateWindow("Working Of DNS!");
	glEnable( GL_TEXTURE_2D );
	glutFullScreen();
    glutKeyboardFunc(mykey);
    glutDisplayFunc(display);
    myinit();
	glutMainLoop();
    return 0;
}
