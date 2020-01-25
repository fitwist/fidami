#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #f9f9fa;");
    ui->mainToolBar->hide();

    QFile plot_data;
    QString data;
    QStringList coordinateList;

    plot_data.setFileName("/Repositories/fidami/fidami/dataset/line-line.csv");
    plot_data.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream ts(&plot_data);

    if (QFile::exists("/Users/helenkapatsa/Repositories/fidami/fidami/dataset/line-line.csv") &&
        QFile::exists("/Users/helenkapatsa/Repositories/fidami/fidami/dataset/area-area.csv") &&
        QFile::exists("/Users/helenkapatsa/Repositories/fidami/fidami/dataset/bar-bar.csv")) {
        ui->statusBar->showMessage(tr("Файлы успешно импортированы"));
    } else {
        ui->statusBar->showMessage(tr("Ошибка импорта файлов"));
    }
    plot_data.close();

    // установка оформления statusBar
    ui->statusBar->setStyleSheet("background-color: #f9f9fa; color: #15b920");
    ui->statusBar->setFont(QFont("Consolas", 14));

    showAreaChart();
    showLineChart();
    showBarChart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showLineChart()
{
    QtCharts::QSplineSeries *series0 = new QtCharts::QSplineSeries();
    series0->setName("Вес утяжелений, кг");

    QFile plot_data;
    QString data;
    QStringList coordinateList;

    plot_data.setFileName("/Users/helenkapatsa/Repositories/fidami/fidami/dataset/line-line.csv");
    plot_data.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream ts(&plot_data);
    QString line;
    while(!ts.atEnd()) {
        line = ts.readLine();
        QStringList list = line.split(";");
        double x,y;
        x = list.at(2).toDouble();
        y = list.at(0).toDouble();
        series0->append(x,y); 
    }

    plot_data.close();

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series0);
    chart->createDefaultAxes();
    chart->setTitle("Дневник тренировок: силовая динамика");
    QPen pen(QRgb(0x1a73e8));
    pen.setWidth(3);
    series0->setPen(pen);

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->lineChartFrame->setLayout(new QVBoxLayout(ui->lineChartFrame));
    ui->lineChartFrame->layout()->addWidget(chartView);
}

void MainWindow::showAreaChart()
{
    QtCharts::QLineSeries* series0 = new QtCharts::QLineSeries();
    QtCharts::QLineSeries* series1 = new QtCharts::QLineSeries();

    *series0 << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6)
                 << QPointF(16, 7) << QPointF(18, 5);
    *series1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2) << QPointF(12, 3)
                 << QPointF(16, 4) << QPointF(18, 3);

//    QFile plot_data;
//    QString data;
//    QStringList coordinateList;

//    plot_data.setFileName("/Users/helenkapatsa/Repositories/fidami/fidami/dataset/area-area.csv");
//    plot_data.open(QIODevice::ReadOnly | QIODevice::Text);

//    QTextStream ts(&plot_data);
//    QString line;
//    while(!ts.atEnd()) {
//        line = ts.readLine();
//        QStringList list = line.split(";");
//        double x,y,z;
//        x = list.at(0).toDouble();
//        y = list.at(2).toDouble();
//        z = list.at(3).toDouble();
//        *series0 << QPointF(x, y);
//        *series1 << QPointF(x, z);
//    }

//    plot_data.close();

    QtCharts::QAreaSeries *series = new QtCharts::QAreaSeries(series0, series1);
    series->setName("Энергозатраты и энергопотребление");
    QPen pen(0xec4f80);
    pen.setWidth(3);
    series->setPen(pen);

    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(0.0, 0xfde8ef);
    gradient.setColorAt(1.0, 0xfde8ef);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    series->setBrush(gradient);

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Дневник питания: энергетический баланс, тыс. ккал");
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0, 20);
    chart->axes(Qt::Vertical).first()->setRange(0, 20);

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->areaChartFrame->setLayout(new QVBoxLayout(ui->areaChartFrame));
    ui->areaChartFrame->layout()->addWidget(chartView);
}

void MainWindow::showBarChart()
{
    QtCharts::QBarSet *set0 = new QtCharts::QBarSet("Жировая масса");
    QtCharts::QBarSet *set1 = new QtCharts::QBarSet("Активная клеточная масса");
    QtCharts::QBarSet *set2 = new QtCharts::QBarSet("Общая масса воды");

    QFile plot_data;
    QString data;
    QStringList coordinateList;

    plot_data.setFileName("/Users/helenkapatsa/Repositories/fidami/fidami/dataset/bar-bar.csv");
    plot_data.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream ts(&plot_data);
    QString line;
    while(!ts.atEnd()) {
        line = ts.readLine();
        QStringList list = line.split(";");
        double x,y,z;
        x = list.at(2).toDouble();
        y = list.at(3).toDouble();
        z = list.at(4).toDouble();
        *set0 << x;
        *set1 << y;
        *set2 << z;
    }

    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Биоимпеданс: состав тела, кг");

    QStringList categories;
    while(!ts.atEnd()) {
        line = ts.readLine();
        QStringList list = line.split(";");
        QString w;
        w = list.at(0);
        categories << w;
    }

    plot_data.close();
    QtCharts::QBarCategoryAxis *axisX = new QtCharts::QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
    axisY->setRange(0,50);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->barChartFrame->setLayout(new QVBoxLayout(ui->barChartFrame));
    ui->barChartFrame->layout()->addWidget(chartView);
}
