target_sources(g4 PRIVATE
    g4_DirectGenerator.h
    g4_Generator.h
    g4_IGeometryProvider.h
    g4_IInterpolator.h
    g4_IMeshBuffer.h
    g4_IMeshProvider.h
    g4_IPointGenerator.h
    g4_Types.h
)

add_subdirectory(detail)