#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    alto  = 500;
    ancho = 500;
    dt = 0.5;

    timer = new QTimer(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(-alto/2,-ancho/2,alto,ancho);

    setStyleSheet("MainWindow {background-image:url(:/new/espacio/espacio.jpg)}");

    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();

    timer->stop();
    connect(timer,SIGNAL(timeout()),this, SLOT(actualizar()));

}

MainWindow::~MainWindow() // Destructor de MainWindow
{
    delete ui;
    delete timer;
    delete scene;
}

void MainWindow::actualizar()
{   // se llama cada vez que el temporizador emite una señal de tiempo transcurrido

    //calcular y aplicar la aceleración de un cuerpo en función de la interacción con otro cuerpo.
    for (int i = 0 ; i < cuerpos.size() ; i++  ) {
        for (int j = 0 ; j < cuerpos.size() ; j++ ) {
            if (i != j){
                cuerpos.at(i)->getEsf()->acelerar(cuerpos.at(j)->getEsf()->getPX(),cuerpos.at(j)->getEsf()->getPY(),cuerpos.at(j)->getEsf()->getMasa());
                cuerpos.at(i)->actualizar(dt);
            }
        }
    }
}

void MainWindow::on_Iniciar_simulacion_clicked()
{
    // iniciar el temporizador para que la función actualizar() se llame periodicamente
    timer->start(dt);
}

void MainWindow::on_Crear_clicked()
{
    // de la interfazar tomar los valores causadas asociados
    float posx = ui->Posicionx->text().toFloat();
    float posy = ui->Posiciony->text().toFloat();
    float masa = ui->Masa->text().toFloat();
    float radio = ui->Radio->text().toFloat();
    float velx = ui->Velocidadx->text().toFloat();
    float vely = ui->Velocidady->text().toFloat();

    cuerpos.append(new cuerpograf(posx,posy,velx,vely,masa,radio)); // agregar el planeta a cuerpos
    scene->addItem(cuerpos.back()); // Agrega el objeto recien creado a la escena
    cuerpos.back()->actualizar(dt); // Al ultimo ingresado lo actualiza

    // limpiar de los campos de entrada
    ui->Posicionx->clear();
    ui->Posiciony->clear();
    ui->Masa->clear();
    ui->Radio->clear();
    ui->Velocidadx->clear();
    ui->Velocidady->clear();
}
