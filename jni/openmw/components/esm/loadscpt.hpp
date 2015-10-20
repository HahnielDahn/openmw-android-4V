#ifndef OPENMW_ESM_SCPT_H
#define OPENMW_ESM_SCPT_H

#include <string>
#include <vector>

#include "esmcommon.hpp"

namespace ESM
{

class ESMReader;
class ESMWriter;

/*
 * Script definitions
 */

class Script
{
public:
    static unsigned int sRecordId;

    struct SCHDstruct
    {
        /// Data from script-precompling in the editor.
        /// \warning Do not use them. OpenCS currently does not precompile scripts.
        int mNumShorts, mNumLongs, mNumFloats, mScriptDataSize, mStringTableSize;
    };
    struct SCHD
    {
        NAME32              mName;
        Script::SCHDstruct  mData;
    }; // 52 bytes

    std::string mId;

    SCHDstruct mData;

    /// Variable names generated by script-precompiling in the editor.
    /// \warning Do not use this field. OpenCS currently does not precompile scripts.
    std::vector<std::string> mVarNames;

    /// Bytecode generated from script-precompiling in the editor.
    /// \warning Do not use this field. OpenCS currently does not precompile scripts.
    std::vector<unsigned char> mScriptData;

    /// Script source code
    std::string mScriptText;

    void load(ESMReader &esm);
    void save(ESMWriter &esm) const;

    void blank();
    ///< Set record to default state (does not touch the ID/index).

private:
    void loadSCVR(ESMReader &esm);
};
}
#endif