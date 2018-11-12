#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    //remove all temp files used (files that were not saved will be deleted)
    temp.remove("out1.bmp");
    temp.remove("out2.bmp");
    temp.remove("out3.bmp");
    temp.remove("out4.bmp");
    delete ui;
}

void MainWindow::on_inputfile_clicked()
{
    originalFilename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.bmp*)"));

     if(QString::compare(originalFilename, QString()) != 0)
     {
         QImage image;
         bool valid = image.load(originalFilename);

         if(valid)
         {

             int i=0, pixelDataStart=0, pixelWidth=0, pixelHeight=0, nbrOfColors=0;
             streampos size;

             frame *fptr;
             fptr = new frame;
             histEqual *heptr;
             heptr = new histEqual;

             vector<frame>bmpFileIn;
             vector<frame>bmpFileOut;
             vector<frame>overlay;
             vector<frame>colorFile;

             vector<histEqual>heData;

             char *memblock;

             if(valid)
             {
                 image = image.scaledToWidth(ui->displayOriginal->width(), Qt::SmoothTransformation);
                 ui->displayOriginal->setPixmap(QPixmap::fromImage(image));
             }

             string heFileName = originalFilename.toStdString();

             original.load(originalFilename);

             ifstream inFile (heFileName, ios::in|ios::binary|ios::ate);
             if (inFile.is_open())
             {
                 size = inFile.tellg();
                 memblock = new char [size];
                 inFile.seekg (0, ios::beg);
                 inFile.read (memblock, size);
                 inFile.close();
             }
             else
             {
                 cout << "Unable to open input file" << endl;
                 return;
             }

             fptr->setInputData(fptr, memblock, bmpFileIn, size);
             fptr->setInputData(fptr, memblock, bmpFileOut, size);
             fptr->setInputData(fptr, memblock, colorFile, size);
             pixelDataStart = fptr->compute4Bytes(bmpFileIn, 10);
             pixelWidth = fptr->compute4Bytes(bmpFileIn, 18);
             pixelHeight = fptr->compute4Bytes(bmpFileIn, 22);
             nbrOfColors = fptr->compute4Bytes(bmpFileIn, 46);

             delete[] memblock;

             fptr->setHistogramVector(colorFile, pixelDataStart, pixelWidth, pixelHeight);
             heptr->setHistData(heptr, colorFile, heData);
             heptr->computeCDF(heData);
             heptr->computeHE(heData, nbrOfColors, pixelWidth, pixelHeight);

     //function call to set the the new pixel data for the output file with HE values
             fptr->setOutputData(bmpFileOut, heData, pixelDataStart, pixelWidth);

     //opens the output file, creates the character array on the heap, writes the
     //the character array to the output file, and closes the output file
             ofstream outFile ("out2.bmp", ios::out|ios::binary);
             if (outFile.is_open())
             {
                 memblock = new char [size];

                 for (i=0; i<size; i++)
                 {
                     memblock[i] = fptr->getCharBlockValue(bmpFileOut, i);
                 }

                 outFile.write (memblock, size);
                 outFile.close();
             }
             else
             {
                 cout << "Unable to open output file" << endl;
                 return;
             }
             cout << "The image file is \"out2.bmp\"" << endl << endl;
             output.load("out2.bmp");
             original = original.scaledToWidth(ui->displayOriginal->width(), Qt::SmoothTransformation);
             ui->displayOriginal->setPixmap(QPixmap::fromImage(original));
             output = output.scaledToWidth(ui->displayHE->width(), Qt::SmoothTransformation);
             ui->displayHE->setPixmap(QPixmap::fromImage(output));

     //clears all vector arrays
             bmpFileIn.clear();
             bmpFileOut.clear();
             colorFile.clear();
             heData.clear();

     //deletes the character array off the heap
             delete[] memblock;
             image.scaledToWidth(ui->displayBright->width(), Qt::SmoothTransformation);
             ui->displayBright->setPixmap(QPixmap::fromImage(image));

             image.scaledToWidth(ui->displayContrast->width(), Qt::SmoothTransformation);
             ui->displayContrast->setPixmap(QPixmap::fromImage(image));
         }
         else
         {

             //idk if else.... if else it would crash

         }
     }

}

void MainWindow::on_inputfile_2_clicked()
{
    overlayFilename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.bmp)"));

    int i=0, pixelDataStart=0, pixelWidth=0;//, pixelHeight=0, nbrOfColors=0;
    streampos size;

    frame *fptr;
    fptr = new frame;


    vector<frame>bmpFileIn;
    vector<frame>bmpFileOut;
    vector<frame>overlay;
    vector<frame>colorFile;

    vector<histEqual>heData;

    char *memblock;

    QString oo = overlayFilename;
    string olFileName = oo.toStdString();
     if(QString::compare(overlayFilename, QString()) != 0)
     {
         //print the image of the overlay with white background
         QImage image;
         bool valid = image.load(oo);
         image = image.scaledToWidth(ui->displayOverlay->width(), Qt::SmoothTransformation);
         ui->displayOverlay->setPixmap(QPixmap::fromImage(image));

         if(valid)
         {
                 QString ff = originalFilename;
                 QString oo = overlayFilename;
                 string inFileName = ff.toStdString();
                 string olFileName = oo.toStdString();
                 ifstream inFile (inFileName, ios::in|ios::binary|ios::ate);
                 if (inFile.is_open())
                 {
                     size = inFile.tellg();
                     memblock = new char [size];
                     inFile.seekg (0, ios::beg);
                     inFile.read (memblock, size);
                     inFile.close();
                 }
                 else
                 {
                     cout << "Unable to open input file" << endl;
                     return;
                 }

                 fptr->setInputData(fptr, memblock, bmpFileOut, size);
                 delete[] memblock;

                 ifstream olFile (olFileName, ios::in|ios::binary|ios::ate);
                 if (olFile.is_open())
                 {
                     size = olFile.tellg();
                     memblock = new char [size];
                     olFile.seekg (0, ios::beg);
                     olFile.read (memblock, size);
                     olFile.close();
                 }
                 else
                 {
                     cout << "Unable to open overlay file" << endl;
                     return;
                 }
                 fptr->setInputData(fptr, memblock, overlay, size);
                 delete[] memblock;

                 pixelDataStart = fptr->compute4Bytes(bmpFileOut, 10);
                 pixelWidth = fptr->compute4Bytes(bmpFileOut, 18);
                 fptr->setOverlay(bmpFileOut, overlay, pixelDataStart, pixelWidth);

                 ofstream outFile ("out1.bmp", ios::out|ios::binary);
                 if (outFile.is_open())
                 {
                     memblock = new char [size];
                     for (i=0; i<size; i++)
                     {
                         memblock[i] = fptr->getCharBlockValue(bmpFileOut, i);
                     }

                     outFile.write (memblock, size);
                     outFile.close();
                 }
                 else
                 {
                     cout << "Unable to open output file" << endl;
                     return;
                 }
                 cout << "The image file is \"out1.bmp\"" << endl << endl;
                 output.load("out1.bmp");
                 output = output.scaledToWidth(ui->displayOverlayNOHE->width(), Qt::SmoothTransformation);
                 ui->displayOverlayNOHE->setPixmap(QPixmap::fromImage(output));
                //clears all vector arrays
                 bmpFileOut.clear();
                 overlay.clear();

                //deletes the character array off the heap
                 delete[] memblock;
         }

    }
}



void MainWindow::on_contrastSlider_valueChanged(int value)
{
    ui->contrastSlider->setDisabled(true);
    original.load("out3.bmp");


    original = original.scaledToWidth(ui->displayContrast->width(), Qt::SmoothTransformation);
    ui->displayContrast->setPixmap(QPixmap::fromImage(original));

    int i=0, pixelDataStart=0;//, pixelWidth=0;//, pixelHeight=0, nbrOfColors=0;
    streampos size;

    frame *fptr;
    fptr = new frame;
    //histEqual *heptr;
    //heptr = new histEqual;

    vector<frame>bmpFileIn;
    vector<frame>bmpFileOut;
    vector<frame>overlay;
    vector<frame>colorFile;

    vector<histEqual>heData;

    char *memblock;
    string conFile = "out3.bmp";

    ifstream inFile (conFile, ios::in|ios::binary|ios::ate);
    if (inFile.is_open())
    {
        size = inFile.tellg();
        memblock = new char [size];
        inFile.seekg (0, ios::beg);
        inFile.read (memblock, size);
        inFile.close();
    }
    else
    {
        cout << "Unable to open input file" << endl;
        return;
    }

    fptr->setInputData(fptr, memblock, bmpFileIn, size);

    delete[] memblock;

    //pass the int value of the slider to a parameter
    int contrastLevel = value;

    pixelDataStart = fptr->compute4Bytes(bmpFileIn, 10);
    fptr->setBrightness(bmpFileIn, pixelDataStart, contrastLevel);

    ofstream outFile ("out4.bmp", ios::out|ios::binary);
    if (outFile.is_open())
    {
        memblock = new char [size];

        for (i=0; i<size; i++)
        {
            memblock[i] = fptr->getCharBlockValue(bmpFileIn, i);
        }

        outFile.write (memblock, size);
        outFile.close();
    }
    else
    {
        cout << "Unable to open output file" << endl;
        return;
    }
    cout << "The image file is \"out4.bmp\"" << endl << endl;

    //clears all vector arrays
    bmpFileIn.clear();

    //deletes the character array off the heap
    delete[] memblock;


    QTextStream(stdout) <<  "Slider value(contrast): " << value << endl;

    original.load(originalFilename);

    output.load("out4.bmp");
    output = output.scaledToWidth(ui->displayContrast->width(), Qt::SmoothTransformation);
    output.save("out4.bmp");
    ui->displayContrast->setPixmap(QPixmap::fromImage(output));
    ui->contrastSlider->setDisabled(false);
}



void MainWindow::on_brightnessSlider_valueChanged(int value)
{
    ui->brightnessSlider->setDisabled(true);
    int i=0, pixelDataStart=0;//, pixelWidth=0;//, pixelHeight=0, nbrOfColors=0;
    streampos size;

    frame *fptr;
    fptr = new frame;
    //heptr = new histEqual;

    vector<frame>bmpFileIn;
    vector<frame>bmpFileOut;
    vector<frame>overlay;
    vector<frame>colorFile;

    vector<histEqual>heData;

    char *memblock;
    QString br = originalFilename;
    string brightFile = br.toStdString();

    ifstream inFile (brightFile, ios::in|ios::binary|ios::ate);
    if (inFile.is_open())
    {
        size = inFile.tellg();
        memblock = new char [size];
        inFile.seekg (0, ios::beg);
        inFile.read (memblock, size);
        inFile.close();
    }
    else
    {
        cout << "Unable to open input file" << endl;
        return;
    }

    fptr->setInputData(fptr, memblock, bmpFileIn, size);

    delete[] memblock;

    //pass the int value of the slider to a parameter
    int brightLevel = value;


    pixelDataStart = fptr->compute4Bytes(bmpFileIn, 10);
    fptr->setBrightness(bmpFileIn, pixelDataStart, brightLevel);

    ofstream outFile ("out3.bmp", ios::out|ios::binary);
    if (outFile.is_open())
    {
        memblock = new char [size];

        for (i=0; i<size; i++)
        {
            memblock[i] = fptr->getCharBlockValue(bmpFileIn, i);
        }

        outFile.write (memblock, size);
        outFile.close();
    }
    else
    {
        cout << "Unable to open output file" << endl;
        return;
    }
    cout << "The image file is \"out3.bmp\"" << endl << endl;

    //clears all vector arrays
    bmpFileIn.clear();

    //deletes the character array off the heap
    delete[] memblock;



    QTextStream(stdout) <<  "Slider value(brightness): " << value << endl;

    original.load(originalFilename);

    output.load("out3.bmp");
    output = output.scaledToWidth(ui->displayBright->width(), Qt::SmoothTransformation);
    output.save("out3.bmp");
    ui->displayBright->setPixmap(QPixmap::fromImage(output));
    ui->brightnessSlider->setDisabled(false);
    ui->displayContrast->setPixmap(QPixmap::fromImage(output));
}


void MainWindow::on_inputfile_3_clicked()
{
    //load the image, name the file, save it, remove old file. (replace out names with custom name)
    output.load("out2.bmp");
   // temp.remove("out2.bmp");
    savef = QFileDialog::getSaveFileName(this, tr("Choose"), "", tr("Images (*.bmp)"));
    output.save(savef);
    QTextStream(stdout) <<  "File Saved Successfully, check the folder."  << endl;
}

void MainWindow::on_inputfile_4_clicked()
{
    output.load("out3.bmp");
   // temp.remove("out3.bmp");
    savef = QFileDialog::getSaveFileName(this, tr("Choose"), "", tr("Images (*.bmp)"));
    output.save(savef);
    QTextStream(stdout) <<  "File Saved Successfully, check the folder."  << endl;
}

void MainWindow::on_inputfile_5_clicked()
{
    output.load("out4.bmp");
    //temp.remove("out4.bmp");
    savef = QFileDialog::getSaveFileName(this, tr("Choose"), "", tr("Images (*.bmp)"));
    output.save(savef);
    QTextStream(stdout) <<  "File Saved Successfully, check the folder."  << endl;
}

void MainWindow::on_inputfile_6_clicked()
{
    output.load("out1.bmp");
    savef = QFileDialog::getSaveFileName(this, tr("Choose"), "", tr("Images (*.bmp)"));
    output.save(savef);
    QTextStream(stdout) <<  "File Saved Successfully, check the folder."  << endl;
}
