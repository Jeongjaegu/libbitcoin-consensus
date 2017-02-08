/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin-consensus.
 *
 * libbitcoin-consensus is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_CONSENSUS_CONSENSUS_HPP
#define LIBBITCOIN_CONSENSUS_CONSENSUS_HPP

#include <cstddef>
#include <bitcoin/consensus/define.hpp>
#include <bitcoin/consensus/export.hpp>
#include "pubkey.h"
#include "script/script_error.h"

// HACK: this symbol is not portable but is used in one place so hardwire here.
#ifndef __func__
#define __func__ "<unknown>"
#endif

namespace libbitcoin {
namespace consensus {
    
// Helper class, not published. This is tested internal to verify_script.
class BCK_API TxInputStream
{
public:
    TxInputStream(const unsigned char* transaction, size_t transaction_size);
    TxInputStream& read(char* destination, size_t size);

private:
    static ECCVerifyHandle secp256k1_context_;
    const unsigned char* source_;
    size_t remaining_;
};

// These are not published in the public header but are exposed here for test.
BCK_API verify_result_type script_error_to_verify_result(ScriptError_t code);
BCK_API unsigned int verify_flags_to_script_flags(unsigned int flags);

} // namespace consensus
} // namespace libbitcoin

#endif
