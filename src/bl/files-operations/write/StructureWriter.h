//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_STRUCTUREWRITER_H
#define UKLADANKA_STRUCTUREWRITER_H

#include <memory>

#include "Writer.h"
#include "../../../includes/misc/StructureFileNameConnection.h"
#include "../Splitter.h"

namespace bl {
    class StructureWriter : public StructureFileNameConnection {
    public:
        template<class T>
        bool write(const T &t) {
            const auto buffer = convert(t);
            auto ptr = std::make_unique<Writer>(getFileName<T>(), getOpenMode<T>(), buffer);
            return ptr->action();
        }

    private:
        template<class T>
        std::string convert(const T &);

        template<class T>
        std::ios_base::openmode getOpenMode() const;
    };

    template<>
    std::string StructureWriter::convert(const Configuration &configuration) {
        return (Configuration::SIDE_SIZE_PARAM_NAME + Configuration::KEY_VALUE_SPLITTER + std::to_string(configuration.sideSize));
    }

    template<>
    std::string StructureWriter::convert(const GameState &gameState) {
        std::string result;
        //todo write timer
        result += std::to_string(gameState.numOfMoves) + '\n';
        result += std::to_string(gameState.sideSize) + '\n';

        std::size_t counter = 0;
        for (size_t i = 0; i < gameState.values.size(); ++i) {
            result += std::to_string(gameState.values[i]);
            ++counter;
            if ((counter % gameState.sideSize) == 0) {
                result += '\n';
            } else {
                result += Splitter::SPLITTER;
            }
        }

        return result;
    }

    template<>
    std::string StructureWriter::convert(const RankTable &rankTable) {
        if (rankTable.table.size() != 1)
            return "";

        std::string result;
        result += rankTable.table[0].name;
        result += rankTable.table[0].time;
        result += rankTable.table[0].numOfMoves;
        return result;
    }

    template<>
    std::ios_base::openmode StructureWriter::getOpenMode<Configuration>() const {
        return std::ios_base::out | std::ios_base::trunc;
    }

    template<>
    std::ios_base::openmode StructureWriter::getOpenMode<GameState>() const {
        return std::ios_base::out | std::ios_base::trunc;
    }

    template<>
    std::ios_base::openmode StructureWriter::getOpenMode<RankTable>() const {
        return std::ios_base::out | std::ios_base::app;
    }
} // bl

#endif //UKLADANKA_STRUCTUREWRITER_H
