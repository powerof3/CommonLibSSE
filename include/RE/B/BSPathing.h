#pragma once

#include "RE/F/FindTriangleForLocationFilterCheckDeltaZ.h"

namespace RE
{
	class BSPathingLockData;
	class BSPathingStreamRead;
	class BSPathingStreamWrite;
	class IDebugText;
	class IMovementParameters;
	class MovementMessage;
	class PathingCell;

	struct BSPathingLocation
	{
		BSPathingLocation(const NiPoint3& a_location, const BSTSmartPointer<BSPathingCell>& a_cell)
		{
			ctor(a_location, a_cell);
		}

		~BSPathingLocation() = default;

		bool ResolveToClosestNavmeshAndTriangle(FindTriangleForLocationFilter& a_filter)
		{
			using func_t = decltype(&BSPathingLocation::ResolveToClosestNavmeshAndTriangle);
			static REL::Relocation<func_t> func{ RELOCATION_ID(87985, 90369) };
			return func(this, a_filter);
		}

		bool GetNavMeshAndTriangle(BSTSmartPointer<BSNavmesh>& a_navMeshOut, std::uint16_t& a_triOut) const
		{
			using func_t = decltype(&BSPathingLocation::GetNavMeshAndTriangle);
			static REL::Relocation<func_t> func{ RELOCATION_ID(87978, 90360) };
			return func(this, a_navMeshOut, a_triOut);
		}

		NiPoint3                       location;          // 00
		BSNavmeshInfo*                 navMeshInfo;       // 10
		BSTArray<BSNavmeshInfo*>*      navMeshInfoArray;  // 18
		BSTSmartPointer<BSPathingCell> pathingCell;       // 20
		std::uint16_t                  triangle;          // 28
		std::uint8_t                   flags;             // 2A
		std::uint8_t                   clientData;        // 2B

	private:
		BSPathingLocation* ctor(const NiPoint3& a_location, const BSTSmartPointer<BSPathingCell>& a_cell)
		{
			using func_t = decltype(&BSPathingLocation::ctor);
			static REL::Relocation<func_t> func{ RELOCATION_ID(87965, 90346) };
			return func(this, a_location, a_cell);
		}
	};
	static_assert(sizeof(BSPathingLocation) == 0x30);

	struct BSVirtualPathingNode
	{
		BSPathingLocation                location;      // 00
		BSTSmartPointer<MovementMessage> actionAtNode;  // 30
	};
	static_assert(sizeof(BSVirtualPathingNode) == 0x38);

	struct BSPathingNode
	{
		BSPathingLocation                location;      // 00
		BSTSmartPointer<MovementMessage> actionAtNode;  // 30;
		NiPoint3                         tangent;       // 38
	};
	static_assert(sizeof(BSPathingNode) == 0x48);

	struct BSPathingSolution : BSIntrusiveRefCounted
	{
		BSTSmallArray<BSVirtualPathingNode, 2> virtualPathingNodes;          // 08
		std::int32_t                           firstLoadedVirtualNodeIndex;  // 88
		std::int32_t                           lastLoadedVirtualNodeIndex;   // 8C
		BSTArray<BSPathingNode>                currentPathingNodes;          // 90
		bool                                   bIncompletePath;              // A8
		bool                                   bRequestGoalUnused;           // A9
	};
	static_assert(sizeof(BSPathingSolution) == 0xB0);

	struct BSPathingStart
	{
		BSPathingLocation location;  // 00
		float             tangent;   // 30
	};
	static_assert(sizeof(BSPathingStart) == 0x38);

	struct BSPathingGoal
	{
		NiPoint3          targetPoint;           // 00
		float             targetAngleTolerance;  // 0C
		BSPathingLocation location;              // 10
		float             zDelta;                // 40
		float             goalRadius;            // 44
		float             normalizeSpeedAtGoal;  // 48
	};
	static_assert(sizeof(BSPathingGoal) == 0x50);

	struct BSPathingAvoidNode
	{
		enum class AvoidNodeType
		{
			AVOID_NODE_SPHERE = 0,
			AVOID_NODE_CYLINDER,
			AVOID_NODE_SPHERE_ACTOR,
			AVOID_NODE_SPHERE_TARGET,
			AVOID_NODE_SPHERE_THREAT,
			AVOID_NODE_SPHERE_OBSTACLE
		};

		NiPoint3                     point1;         // 00
		NiPoint3                     point2;         // 0C
		float                        radius;         // 18
		float                        cost;           // 1C
		REX::TEnumSet<AvoidNodeType> avoidNodeType;  // 20
	};
	static_assert(sizeof(BSPathingAvoidNode) == 0x24);

	struct BSPathingRestrictions
	{
		struct BSPathingSearchAreaRestrictions
		{
			NiPoint3 center;  // 00
			float    radius;  // 08
		};

		NiPointer<BSTArray<BSPathingAvoidNode>> avoidNodeArray;    // 00
		BSPathingSearchAreaRestrictions         areaRestrictions;  // 08
	};
	static_assert(sizeof(BSPathingRestrictions) == 0x18);

	struct BSPathingSearchParameters
	{
		float         preferredCostFactor;     // 00
		float         tangentSmoothingFactor;  // 04
		std::uint16_t retryCount;              // 08
		std::uint16_t flags;                   // 0A
	};
	static_assert(sizeof(BSPathingSearchParameters) == 0xC);

	struct BSPathingActorAttributes
	{
		float                              radius;    // 00
		float                              height;    // 04
		BSTSmartPointer<BSPathingLockData> lockData;  // 08
		std::uint32_t                      data;      // 10
	};
	static_assert(sizeof(BSPathingActorAttributes) == 0x18);

	struct MovementActorAvoidanceParameters
	{
		BSTSmallArray<std::uint32_t, 1> actors;  // 00
		std::uint32_t                   flags;   // 18
	};
	static_assert(sizeof(MovementActorAvoidanceParameters) == 0x20);

	class BSPathingRequest : public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSPathingRequest;
		inline static constexpr auto VTABLE = VTABLE_BSPathingRequest;

		virtual ~BSPathingRequest();  // 00

		// add
		virtual std::uint32_t GetType();                                // 01 - CRC32("BSPathingRequest")
		virtual void          CopyTo(BSPathingRequest& a_dest);         // 02
		virtual void          Write(BSPathingStreamWrite* a_stream);    // 03
		virtual void          Read(BSPathingStreamRead* a_stream);      // 04
		virtual void          CheckValid();                             // 05
		virtual void          PrintDebugText(IDebugText* a_debugText);  // 06

		// members
		BSPathingStart                       start;                             // 10
		BSPathingGoal                        goal;                              // 48
		BSPathingRestrictions                restrictions;                      // 98
		BSPathingSearchParameters            searchParameters;                  // B0
		BSPathingActorAttributes             actorAttributes;                   // C0
		MovementActorAvoidanceParameters     movementActorAvoidanceParameters;  // D8
		BSTSmartPointer<IMovementParameters> defaultParameters;                 // F8
	};
	static_assert(sizeof(BSPathingRequest) == 0x100);

	class BSPathing : public BSTSingletonExplicit<BSPathing>
	{
	public:
		inline static constexpr auto RTTI = RTTI_BSPathing;
		inline static constexpr auto VTABLE = VTABLE_BSPathing;

		virtual ~BSPathing();  // 00

		// add
		virtual BSTArray<BSNavmeshInfo*> GetPotentialNavMeshInfoForLocation(PathingCell* a_cell) = 0;                                             // 01
		virtual bool                     GetAllLoadedNavmeshes1(BSTScrapHashMap<std::uint32_t, BSTSmartPointer<BSNavmesh>>& a_retNavMeshes) = 0;  // 02
		virtual bool                     GetAllLoadedNavmeshes2(BSScrapArray<BSNavmeshInfo*>& a_retNavMeshes) = 0;                                // 03
		virtual bool                     GetAllLoadedNavmeshes3(BSTArray<BSNavmeshInfo*>& a_retNavMeshes) = 0;                                    // 04
		virtual bool                     GetAllLoadedNavmeshes4(BSScrapArray<BSTSmartPointer<BSNavmesh>>& a_retNavMeshes) = 0;                    // 05
		virtual bool                     GetAllLoadedNavmeshes5(BSTArray<BSTSmartPointer<BSNavmesh>>& a_retNavMeshes) = 0;                        // 06
		virtual FormID                   GetSelectedDebugRef() = 0;                                                                               // 07
		virtual bool                     GetPathingDoorFromCollision(NiAVObject* a_object, BSTSmartPointer<BSPathingDoor>& a_retDoor) = 0;        // 08

		// members
		FindTriangleForLocationFilterCheckDeltaZ defaultTriangleFilter;  // 08
	};
	static_assert(sizeof(BSPathing) == 0x18);
}
