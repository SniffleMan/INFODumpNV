#pragma once

#include "nvse/GameForms.h"  // TESForm, TESFullName


namespace RE
{
	// 40
	class TESTopic :
		public TESForm,		// 00
		public TESFullName	// 18
	{
	public:
		// 34
		struct Info
		{
			TESQuest*							quest;		// 00
			TopicInfoArray						infoArray;	// 04
			BSSimpleArray<INFO_LINK_ELEMENT>	unk01C;		// 1C
			TESQuest*							quest2;		// 2C
			UInt8								unk030;		// 30
			UInt8								pad031[3];	// 31
		};


		virtual ~TESTopic();	// 00


		// members
		UInt8	type;		// 24 - DATA
		UInt8	flags;		// 25 - DATA also used as bool or flag, connected to INFOGENERAL
		UInt8	pad26[2];	// 26
		float	priority;	// 28 - PNAM
		Info*	info;		// 2C
		String	unk34;		// 34 - TDUM
		UInt16	unk3C;		// 3C - XIDX
		UInt16	unk3E;		// 3E
	};
}
