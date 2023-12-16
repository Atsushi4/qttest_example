#include <QtTest>

// add necessary includes here

class Test_QString : public QObject
{
    Q_OBJECT

public:
    Test_QString();
    ~Test_QString();

private slots:
    void test_operator_add();
    void test_find();
    void test_find_data();
};

Test_QString::Test_QString() {}

Test_QString::~Test_QString() {}

void Test_QString::test_operator_add() {
    QString str1 = "Hello";
    QString str2 = "World";
    QString str3 = str1 + str2;
    QCOMPARE(str3, QString("HelloWorld"));
}

void Test_QString::test_find()
{
    QFETCH(QString, str1);
    QFETCH(QString, str2);
    QFETCH(int, begin);
    QFETCH(int, expected);

    QCOMPARE(str1.indexOf(str2, begin), expected);
}

void Test_QString::test_find_data()
{
    QTest::addColumn<QString>("str1");
    QTest::addColumn<QString>("str2");
    QTest::addColumn<int>("begin");
    QTest::addColumn<int>("expected");

    QTest::newRow("not found") << "Hello" << "World" << 0 << -1;
    QTest::newRow("found") << "Hello" << "ll" << 0 << 2;
}

QTEST_APPLESS_MAIN(Test_QString)

#include "tst_test_qstring.moc"
