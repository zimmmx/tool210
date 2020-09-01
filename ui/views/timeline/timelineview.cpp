#include "timelineview.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include "cliplistview.h"
#include "cliplistmodel.h"

TimelineView::TimelineView(ClipListModel *model, QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *secondaryLayout = new QHBoxLayout();

    clipListView = new ClipListView(this);
    runPauseButton = new QPushButton("Play/Pause");
    zoomLabel = new QLabel("Zoom: 100 %");
    timeLabel = new QLabel("Time: 10 s");

    clipListView->setModel(model);


    mainLayout->addLayout(secondaryLayout);
    mainLayout->addWidget(clipListView);

    secondaryLayout->addWidget(runPauseButton);
    secondaryLayout->addWidget(timeLabel);
    secondaryLayout->addStretch();
    secondaryLayout->addWidget(zoomLabel);

    setLayout(mainLayout);

    connect(clipListView, SIGNAL(zoomChanged(float)), this, SLOT(setZoomLabel(float)));
    connect(clipListView, SIGNAL(timeChanged(float)), this, SLOT(setTimeLabel(float)));
    connect(clipListView, SIGNAL(timeChanged(float)), this, SIGNAL(timeChanged(float)));
    connect(clipListView, SIGNAL(clipToRenderChanged(int)), this, SIGNAL(clipToRenderChanged(int)));
}

void TimelineView::setController(TimelineController *timelineController)
{
    connect(runPauseButton, SIGNAL(clicked()), timelineController, SIGNAL(playPauseClicked()));
    connect(this, SIGNAL(timeChanged(float)), timelineController, SIGNAL(timeChanged(float)));
}

void TimelineView::setZoomLabel(float zoom)
{
    zoomLabel->setText(QString("Zoom: %1 %").arg(zoom*100.0f));
}

void TimelineView::setTimeLabel(float time)
{
    timeLabel->setText(QString("Time: %1 s").arg(time));
}

void TimelineView::setTime(float time)
{
    setTimeLabel(time);
    clipListView->setTime(time);
}