#include "Sedan.h"


namespace assignment2
{

	Sedan::Sedan() : Vehicle(4)
	{
		//std::cout << "Sedan 생성자 호출" << std::endl;
		mTrailer = nullptr;
		mbIsConnected = false;
		InitTravel(5, 1);
	}

	Sedan::Sedan(const Sedan& other) : Vehicle(other)
	{
		//std::cout << "Sedan 생성자 호출" << std::endl;
		if (other.mbIsConnected)
		{
			mTrailer = new Trailer(other.mTrailer->GetWeight());
			mbIsConnected = true;
			InitTravel(5, 2);
		}
		else
		{
			mbIsConnected = false;
			mTrailer = nullptr;
			InitTravel(5, 1);
		}
	}




	Sedan::~Sedan()
	{
		//std::cout << "Sedan 소멸자 호출" << std::endl;
		if (mbIsConnected)
		{
			delete mTrailer;
			mTrailer = nullptr;
			mbIsConnected = false;
		}
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int passengerTotalWeight = GetTotalPassengerWeight();

		if (mbIsConnected)
		{
			passengerTotalWeight += mTrailer->GetWeight();
		}
		if (passengerTotalWeight <= 80)
		{
			return 480;
		}
		if (80 < passengerTotalWeight && passengerTotalWeight <= 160)
		{
			return 458;
		}
		if (160 < passengerTotalWeight && passengerTotalWeight <= 260)
		{
			return 400;
		}
		if (260 < passengerTotalWeight && passengerTotalWeight <= 350)
		{
			return 380;
		}
		if (passengerTotalWeight > 350)
		{
			return 300;
		}
		return 0;
	}

	Sedan& Sedan::operator=(const Sedan& rhs)
	{
		if (this != &rhs)
		{
			for (unsigned int i = 0; i < mSize; i++)
			{
				delete mPassenger[i];
			}
			mTotalPassengerWeight = rhs.mTotalPassengerWeight;
			mSize = rhs.mSize;
			mMaxPassengersCount = rhs.mMaxPassengersCount;
			mNowRestCount = rhs.mNowRestCount;
			mMustRestCount = rhs.mMustRestCount;
			mMaxMoveCount = rhs.mMaxMoveCount;
			mNowMoveCount = rhs.mNowMoveCount;
			mTotalMoveCount = rhs.mTotalMoveCount;

			for (unsigned int i = 0; i < mMaxPassengersCount; i++)
			{
				mPassenger[i] = nullptr;
			}


			for (unsigned int i = 0; i < mSize; i++)
			{
				mPassenger[i] = new Person(*rhs.mPassenger[i]);
			}
			if (rhs.mbIsConnected)
			{
				if (mbIsConnected)
				{
					delete mTrailer;
					mTrailer = nullptr;
					mbIsConnected = false;
				}
				mTrailer = new Trailer(rhs.mTrailer->GetWeight());
				mbIsConnected = true;

				InitTravel(5, 2);
			}
			else
			{
				delete mTrailer;
				mTrailer = nullptr;
				mbIsConnected = false;

				InitTravel(5, 1);
			}

		}
		return *this;
	}


	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mbIsConnected || trailer == nullptr)
		{
			return false;
		}
		InitTravel(5, 2);
		mTrailer = trailer;
		mbIsConnected = true;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mbIsConnected)
		{
			delete mTrailer;
			mTrailer = nullptr;
			mbIsConnected = false;
			return true;
		}
		return false;
	}
}
