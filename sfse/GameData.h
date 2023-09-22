#pragma once

#include "sfse/GameTypes.h"
#include "sfse/GameForms.h"
#include "sfse/GameEvents.h"
#include "sfse/NiTypes.h"

class TESForm;
class TESRegionList;
class BGSAddonNode;
class TESPackedFile;

class TESFile
{
public:
	virtual ~TESFile();

	u64	unk08;
	void*	unk10;
	u64	unk18;
	u64	unk20;
	u64	unk28;
	u64	unk30;
	char filePath[0x104]; // 38
	u32	unk13C;
	u64	unk140;
	u64	unk148;
	u64	unk150;
	u64	unk158;
	u64	unk160;
	u64	unk168;
	u64	unk170;
	u64	unk178;
	u64	unk180;
	u64	unk188;
	u64	unk190;
	u64	unk198;
	u64	unk1A0;
	u32	unk1A8;
	u32	unk1AC;
	u32	unk1B0;
	u32	unk1B4;
	u64	unk1B8;
	BSTArray<BSFixedString> unk1C0;
	BSTArray<TESFile*> unk1D0;
	BSTArray<TESFile*> unk1E0;
	u64	unk1F0[(0x250 - 0x1F0) >> 3];
};
static_assert(sizeof(TESFile) == 0x250);

class TESPackedFile : public TESFile
{
public:
	virtual ~TESPackedFile();

	u64	unk250[(0x3B8 - 0x250) >> 3];
};
static_assert(sizeof(TESPackedFile) == 0x3B8);

class TESDataHandler : 
	public BSTEventSource<BGSHotloadCompletedEvent>
{
public:
	virtual ~TESDataHandler();

	struct FormItem
	{
		u64	unk00;
		BSTArray<TESForm*> pFormsA;
	};

	struct TESFileCollection
	{
		BSTArray<TESFile*> FileA;
		BSTArray<TESFile*> SmallFileA;
	};


	void* unk28; // BSService::Detail::TService<BSService::Detail::TServiceTraits<TESDataHandler,BSService::Detail::ReferenceGetterDefaultPointer<TESDataHandler *>>>
	u64	unk30;
	u64	unk38;
	u64	unk40;
	u64	unk48;
	u64	unk50;
	u64	unk58;
	u64	unk60;
	u64	unk68;
	FormItem pFormArray[FormType::kTotal];
	TESRegionList* unk1498;
	BSTArray<void*> unk14A0;
	u64	unk14B0;
	NiTPrimitiveArray<BGSAddonNode*> unk14B8;
	u64	unk14D0;
	u64	unk14D8;
	u64	unk14E0;
	u64	unk14E8;
	BSSimpleList<TESPackedFile*> listFiles; // 14F0
	TESFileCollection CompiledFileCollection; // 1500
	u64	unk1520;
	u64 unk1528[(0x1718 - 0x1528) >> 3];

	static TESDataHandler* GetSingleton()
	{
		RelocPtr<TESDataHandler*> singleton(0x054CB028);
		return *singleton;
	}
};
static_assert(offsetof(TESDataHandler, pFormArray) == 0x70);
static_assert(offsetof(TESDataHandler, listFiles) == 0x14F0);
static_assert(offsetof(TESDataHandler, unk1520) == 0x1520);