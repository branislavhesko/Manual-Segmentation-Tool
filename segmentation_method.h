#pragma once
class SegmentationMethod
{
protected:
    bool is_running = false;
public:
    void setIsRunning(bool isRunning);

public:
    bool isRunning() const;

public:
	SegmentationMethod();
	virtual ~SegmentationMethod();
};

