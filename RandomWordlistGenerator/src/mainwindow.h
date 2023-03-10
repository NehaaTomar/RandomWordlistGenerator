/*
* This file is part of Random Wordlist Generator
*
* (C) Francesco Mondello 2013 - 2014
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* Contact e-mail: Faster <faster3ck@gmail.com>
*
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include "wordgenerator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    WordGenerator *wordGen;
    int m_index;    // the current index
    int m_max_index;
    bool wordlist_thread_started;
    QTextStream m_outText;

    void startPasswordGeneration();
    void generatePassword();
    void setCharacterSets();
    bool checkCurrentSets();

    void setGuiCheckstates_ALL();
    void setGuiCheckstates_CUSTOM();

    void saveFileOutput();

    void disableInterface(bool status);

private slots:
    void setCurrentPassword(QString password);
    void on_pushGenerate_clicked();
    void on_checkAll_clicked();
    void on_checkCustomChar_clicked();
    void on_pushSave_clicked();
    void on_action_Close_triggered();
    void on_action_About_triggered();
};

#endif // MAINWINDOW_H
