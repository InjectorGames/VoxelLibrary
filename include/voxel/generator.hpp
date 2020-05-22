#pragma once
#include <voxel/structure.hpp>

// TODO: switch to FastNoise2
// https://github.com/Auburns/FastNoise2
#include <FastNoiseSIMD/FastNoiseSIMD.h>

namespace VOXEL_NAMESPACE
{
	// TODO: make this class abstract as mesh generator
	class Generator
	{
	protected:
		FastNoiseSIMD* fastNoise;
	public:
		Generator(int seed = 1337)
		{
			fastNoise = FastNoiseSIMD::NewFastNoiseSIMD(seed);
		}
		virtual ~Generator()
		{
			delete fastNoise;
			fastNoise = nullptr;
		}

		inline void generateRandom(Sector& sector,
			const VOXEL_ID_TYPE id,
			const int32_t chance = 50,
			const uint32_t seed = 1337) const
		{
			if (chance < 0 || chance > 100)
				throw std::range_error("Chance out of range");

			srand(seed);

			const auto modulo = 10000 / chance;

			for (size_t i = 0; i < VOXEL_SECTOR_SIZE; i++)
			{
				if(rand() % modulo < 100)
					sector.setID(i, id);
			}
		}
		inline void generateRandom(Structure& structure,
			const VOXEL_ID_TYPE id,
			const int32_t chance = 50,
			const uint32_t seed = 1337) const
		{
			for (size_t i = 0; i < structure.getSize(); i++)
			{
				auto& sector = structure.get(i);
				generateRandom(sector, id, chance, seed);
			}
		}

		inline void generateMesh(Mesh& mesh,
			const Register& _register,
			const Cluster& cluster)
		{
			for (size_t z = 0; z < VOXEL_SECTOR_LENGTH; z++)
			{
				for (size_t y = 0; y < VOXEL_SECTOR_LENGTH; y++)
				{
					for (size_t x = 0; x < VOXEL_SECTOR_LENGTH; x++)
					{
						const auto id = cluster.center.getID(x, y, z);
						const auto& voxel = _register.get(id);

						if (voxel.renderer)
							voxel.renderer->generate(
								mesh, _register, cluster, x, y, z);
					}
				}
			}
		}
	};
}