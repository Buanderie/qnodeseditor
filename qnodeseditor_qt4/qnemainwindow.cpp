/* Copyright (c) 2012, STANISLAW ADASZEWSKI
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of STANISLAW ADASZEWSKI nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL STANISLAW ADASZEWSKI BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#include "qnemainwindow.h"
#include "ui_qnemainwindow.h"

#include "qneblock.h"
#include "qnodeseditor.h"

#include <QGraphicsScene>
#include <QFileDialog>

#include "qneport.h"

QNEMainWindow::QNEMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QNEMainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *s = new QGraphicsScene();
    ui->graphicsView->setScene(s);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    // ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    QNEBlock *b = new QNEBlock(0, s);
    b->addPort("test", 0, QNEPort::NamePort);
    b->addPort("TestBlock", 0, QNEPort::TypePort);
    b->addInputPort("in1");
    b->addInputPort("in2");
    b->addInputPort("in3");
    b->addOutputPort("out1");
    b->addOutputPort("out2");
    b->addOutputPort("out3");

    b = b->clone();
    b->setPos(150, 0);

    b = b->clone();
    b->setPos(150, 150);

    nodesEditor = new QNodesEditor(this);
    nodesEditor->install(s);

    connect(ui->action_Save, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->action_Load, SIGNAL(triggered()), this, SLOT(loadFile()));
    connect(ui->action_Quit, SIGNAL(triggered()), qApp, SLOT(quit()));

    ui->toolBar->addAction("Add block", this, SLOT(addBlock()));
}

QNEMainWindow::~QNEMainWindow()
{
    delete ui;
}

void QNEMainWindow::saveFile()
{
	QString fname = QFileDialog::getSaveFileName();
	if (fname.isEmpty())
		return;

	QFile f(fname);
	f.open(QFile::WriteOnly);
	QDataStream ds(&f);
	nodesEditor->save(ds);
}

void QNEMainWindow::loadFile()
{
	QString fname = QFileDialog::getOpenFileName();
	if (fname.isEmpty())
		return;

	QFile f(fname);
	f.open(QFile::ReadOnly);
	QDataStream ds(&f);
	nodesEditor->load(ds);
}

void QNEMainWindow::addBlock()
{
	QNEBlock *b = new QNEBlock(0, ui->graphicsView->scene());
	static const char* names[] = {"Vin", "Voutsadfasdf", "Imin", "Imax", "mul", "add", "sub", "div", "Conv", "FFT"};
	for (int i = 0; i < 4 + rand() % 3; i++)
	{
		b->addPort(names[rand() % 10], rand() % 2, 0, 0);
		b->setPos(ui->graphicsView->sceneRect().center().toPoint());
	}
}
