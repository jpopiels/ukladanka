//
// Created by pc on 06.09.2023.
//

#ifndef UKLADANKA_STRUCTUREREADER_H
#define UKLADANKA_STRUCTUREREADER_H

#include <memory>
#include <cstring>

#include "Reader.h"
#include "../../../includes/misc/StructureFileNameConnection.h"
#include "../Splitter.h"

namespace bl {
    class StructureReader : public StructureFileNameConnection {
    public:
        template<class T>
        bool read(T& t) {
            Lines lines;
            auto ptr = std::make_unique<Reader>(getFileName<T>(), std::ios_base::in, lines);

            if (!ptr->action())
                return false;

            t = convert<T>(lines);
            return true;
        }

    private:
        template<class T>
        T convert(const Lines&);
    };

    template<>
    Configuration StructureReader::convert(const Lines &lines) {
        Configuration configuration{};

        if (lines.size() != 1)
            return {};

        const auto split = Splitter::split(lines[0], Configuration::KEY_VALUE_SPLITTER);

        if (split.size() != 2 || strcmp(split[0].c_str(), Configuration::SIDE_SIZE_PARAM_NAME) != 0)
            return {};

        try {
            configuration.sideSize = std::stoull(split[1]);
        }
        catch(const std::invalid_argument&) {
            //todo
            return {};
        }
        catch(const std::out_of_range&) {
            //todo
            return {};
        }
        return configuration;
    }

    template<>
    GameState StructureReader::convert(const Lines &lines) {
        GameState gameState{};
        try {
            for (size_t i = 0; i < lines.size(); ++i) {
                if (i == 0) {
                    //todo load timer
                }
                else if (i == 1) {
                    gameState.numOfMoves = std::stoull(lines[i]);
                }
                else if (i == 2) {
                    gameState.sideSize = std::stoull(lines[i]);

                    if (lines.size() - 3 != gameState.sideSize)
                        return {};
                }
                else {
                    const auto split = Splitter::split(lines[i]);
                    for (const auto & param : split) {
                        gameState.values.emplace_back(std::stoull(param));
                    }
                }
            }
        }
        catch(const std::invalid_argument&) {
            //todo
            return {};
        }
        catch(const std::out_of_range&) {
            //todo
            return {};
        }
        return gameState;
    }

    template<>
    RankTable StructureReader::convert(const Lines &lines) {
        RankTable rankTable{};
        for (const auto & line : lines) {
            const auto split = Splitter::split(line);

            if (split.size() != 3)
                continue;

            rankTable.table.emplace_back(SingleRankTableRecord{split[0], split[1], split[2]});
        }
    }
} // bl

#endif //UKLADANKA_STRUCTUREREADER_H
