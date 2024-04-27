#include "testmood.h"
#include "ui_testmood.h"

TestMood::TestMood(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TestMood)
{
    ui->setupUi(this);

    ui->buttonNextQuestion_2->hide();
    ui->buttonNextQuestion_2->setStyleSheet("background-color: orange;");

    ui->buttonNextQuestion_3->hide();
    ui->buttonNextQuestion_3->setStyleSheet("background-color: yellow;");

    ui->buttonNextQuestion_4->hide();
    ui->buttonNextQuestion_4->setStyleSheet("background-color: blue;");

    ui->buttonNextQuestion_5->hide();
    ui->buttonNextQuestion_5->setStyleSheet("background-color: green;");

    ui->buttonNextQuestion_1->setStyleSheet("background-color: red;");
    ui->button_checkingResults->hide();
    ui->buttonStartPuzzle->hide();
    ui->ShowAnswerEdit->hide();

    QPixmap backgroundImage("/home/nastya/Загрузки/morning.jpg"); // путь к изображению
    ui->PictureForTest->setPixmap(backgroundImage.scaled(ui->PictureForTest->size(), Qt::IgnoreAspectRatio));

    radioButtons = {ui->AnswerNumber_1, ui->AnswerNumber_2, ui->AnswerNumber_3, ui->AnswerNumber_4, ui->AnswerNumber_5};
}

TestMood::~TestMood()
{
    delete ui;
}

void TestMood::on_buttonNextQuestion_1_clicked()
{
    CheckingAnswerOfTest();

    if (check)
    {
        QPixmap backgroundImage("/home/nastya/Загрузки/vegetables.jpg"); // путь к изображению
        ui->PictureForTest->setPixmap(backgroundImage.scaled(ui->PictureForTest->size(), Qt::IgnoreAspectRatio));

        CounterMood();

        ui->TestQuestion->setText("С каким овощем ты можешь себя сравнить?");
        ui->buttonNextQuestion_1->hide();

        ui->buttonNextQuestion_2->show();
        ui->AnswerNumber_1->setText("Счастливый и свежий огурец");
        ui->AnswerNumber_2->setText("Обычная редиска");
        ui->AnswerNumber_3->setText("Измученный картофель");
        ui->AnswerNumber_4->setText("Злой помидор");
        ui->AnswerNumber_5->setText("Раздавленный горох");
    }
}

void TestMood::on_buttonNextQuestion_2_clicked()
{
    CheckingAnswerOfTest();

    if (check)
    {
        QPixmap backgroundImage("/home/nastya/Загрузки/superplay.jpg"); // путь к изображению
        ui->PictureForTest->setPixmap(backgroundImage.scaled(ui->PictureForTest->size(), Qt::IgnoreAspectRatio));

        CounterMood();

        ui->TestQuestion->setText("Если бы вы были супергероем, то какую способность бы хотели иметь?");
        ui->buttonNextQuestion_2->hide();

        ui->buttonNextQuestion_3->show();
        ui->AnswerNumber_1->setText("Летать в облаках из сахарной ваты");
        ui->AnswerNumber_2->setText("Мне и человеком быть нормально");
        ui->AnswerNumber_3->setText("Читать мысли людей");
        ui->AnswerNumber_4->setText("Управлять действиями людей");
        ui->AnswerNumber_5->setText("Какой из меня супергерой");
    }
}

void TestMood::on_buttonNextQuestion_3_clicked()
{
    CheckingAnswerOfTest();

    if (check)
    {
        QPixmap backgroundImage("/home/nastya/Загрузки/music.jpg"); // путь к изображению
        ui->PictureForTest->setPixmap(backgroundImage.scaled(ui->PictureForTest->size(), Qt::IgnoreAspectRatio));

        CounterMood();

        ui->TestQuestion->setText("Какую бы песню вы сейчас послушали?");
        ui->buttonNextQuestion_3->hide();

        ui->buttonNextQuestion_4->show();
        ui->AnswerNumber_1->setText("О весёлых пиявках в пруду");
        ui->AnswerNumber_2->setText("О колючем и спокойном ёжике");
        ui->AnswerNumber_3->setText("О разъярённой пчеле");
        ui->AnswerNumber_4->setText("О зубастом крокодиле");
        ui->AnswerNumber_5->setText("О долгожительнице-черепахе");
    }
}

void TestMood::on_buttonNextQuestion_4_clicked()
{
    CheckingAnswerOfTest();

    if (check)
    {
        QPixmap backgroundImage("/home/nastya/Загрузки/animal.jpg"); // путь к изображению
        ui->PictureForTest->setPixmap(backgroundImage.scaled(ui->PictureForTest->size(), Qt::IgnoreAspectRatio));

        CounterMood();

        ui->TestQuestion->setText("Что бы вы спросили у животных?");
        ui->buttonNextQuestion_4->hide();

        ui->buttonNextQuestion_5->show();
        ui->AnswerNumber_1->setText("Почему они такие милые?");
        ui->AnswerNumber_2->setText("Зачем у них что-то спрашивать?");
        ui->AnswerNumber_3->setText("Почему у них так мало проблем?");
        ui->AnswerNumber_4->setText("Почему большинство из них вечно злые на людей?");
        ui->AnswerNumber_5->setText("Почему мы не понимаем их языка?");
    }
}

void TestMood::on_buttonNextQuestion_5_clicked()
{
    ui->buttonNextQuestion_5->hide();
    ui->button_checkingResults->show();
    ui->ShowAnswerEdit->show();
    QPixmap backgroundImage_1("/home/nastya/Загрузки/intresting.jpg"); // путь к изображению
    ui->PictureForTest->setPixmap(backgroundImage_1.scaled(ui->PictureForTest->size(), Qt::IgnoreAspectRatio));

    ui->TestQuestion->hide();
    ui->AnswerNumber_1->hide();
    ui->AnswerNumber_2->hide();
    ui->AnswerNumber_3->hide();
    ui->AnswerNumber_4->hide();
    ui->AnswerNumber_5->hide();
}

void TestMood::on_button_checkingResults_clicked()
{
    ui->buttonStartPuzzle->show();
    results_ofTest(counterGood, counterNormal, counterIrritated, counterWicked, counterSad);
}

void TestMood::on_buttonStartPuzzle_clicked()
{
    PuzzleThemes *puzzleThemes = new PuzzleThemes();
    puzzleThemes->show();
    this->hide();
}

void TestMood::CheckingAnswerOfTest()
{
    bool checkIn = false;
    for(auto button : radioButtons)
    {
        if(button->isChecked())
        {
            checkIn = true;
        }
    }

    check = checkIn;
}

void TestMood::CounterMood()
{
    int countHelp = 0;
    for(auto button : radioButtons)
    {
        if(button->isChecked() && countHelp == 0) counterGood++;

        if(button->isChecked() && countHelp == 1) counterNormal++;

        if(button->isChecked() && countHelp == 2) counterIrritated++;

        if(button->isChecked() && countHelp == 3) counterWicked++;

        if(button->isChecked() && countHelp == 4) counterSad++;

        countHelp++;
    }
}

void TestMood::results_ofTest(int counterGood, int counterNormal, int counterIrritated, int counterWicked, int counterSad)
{
    QList<int> massMood = {counterGood, counterNormal, counterIrritated, counterWicked, counterSad};
    int max = counterGood;

    for(int i = 0; i < massMood.size(); i++)
    {
        if (massMood[i] > max) max = massMood[i];
    }

    if (max == counterGood) ui->ShowAnswerEdit->setText("У вас хорошее настроение");

    else if (max == counterNormal) ui->ShowAnswerEdit->setText("У вас нормальное настроение");

    else if (max == counterIrritated) ui->ShowAnswerEdit->setText("Вы раздражены");

    else if (max == counterWicked) ui->ShowAnswerEdit->setText("Вы злы");

    else ui->ShowAnswerEdit->setText("У вас плохое настроение");
}