//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbGoing.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib // TbGoing
{
	TbGoing::TbGoing()
	{
		position = NULL;
		station = NULL;
		speedable = NULL;
	}

	TbGoing::TbGoing(TbVector2d *position, TbPoint2d *station,
		TbSpeedable *speedable)
	{
		this->position = position;
		this->station = station;
		this->speedable = speedable;
	}

	TbGoing::~TbGoing()
	{
		if(position)
		{
			delete position;
		}
		if(station)
		{
			delete station;
		}
		if(speedable)
		{
            delete speedable;
        }
	}

	bool TbGoing::moveToStation()
	{
		double speed = speedable->getSpeed();
		if(speed > 0)
		{
			TbVector2d *dir = TbVector2d::instance_((TbPoint2d*)position, station);
			if(dir->getLength() > speed)
			{
				dir->setLength(speed);
				position->shift(dir);
			}
			else
			{
                position->coordinate(station);
            }
			delete dir;
		}
		return !(position->getX() == station->getX() &&
			position->getY() == station->getY());
	}

	void TbGoing::setPosition(TbVector2d *position)
	{
		if(this->position)
		{
			delete this->position;
		}
		this->position = position;
	}

	void TbGoing::setStation(TbPoint2d *station)
	{
		if(this->station)
		{
			delete this->station;
		}
		this->station = station;
	}

	TbVector2d* TbGoing::getPosition()const
	{
		return position;
	}

	TbPoint2d* TbGoing::getStation()const
	{
    	return station;
	}

	void TbGoing::setSpeedable(TbSpeedable *speedable)
	{
		if(this->speedable)
		{
            delete this->speedable;
        }
    	this->speedable = speedable;
	}

	TbSpeedable* TbGoing::getSpeedable()const
	{
    	return speedable;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
