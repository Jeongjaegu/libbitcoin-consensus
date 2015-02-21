/*
 * Copyright (c) 2011-2013 libbitcoin developers (see AUTHORS)
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_CONSENSUS_EXPORT_HPP
#define LIBBITCOIN_CONSENSUS_EXPORT_HPP

#include <cstddef>
#include <cstdint>
#include <bitcoin/consensus/define.hpp>
#include <bitcoin/consensus/version.hpp>

namespace libbitcoin {
namespace consensus {

/**
 * Result codes for script calls.
 */
enum script_verification_result
{
    /**
     * The script verified successfully.
     */
    verified = 0,

    /**
     * The script failed to verify.
     */
     unverified = 1,

    /**
     * The transaction index exceeds the number of transaction inputs.
     */
    invalid_tx_index = 2,

    /**
     * The transaction deserialized to a length other than specified.
     */
    invalid_tx_length = 3,

    /**
     * The transaction failed to deserialize.
     */
    tx_deserialization_failed = 4
};

/**
 * Additional flags for script verification.
 */
enum script_verification_flags
{
    /**
     * No flags.
     */
    none = 0,

    /**
     * Evaluate BIP16 (P2SH subscripts).
     */
    verify_bip16 = (1U << 0),

    /**
     * Enforce BIP66 (strict DER compliance).
     */
    verify_bip66 = (1U << 2)
};

/**
 * Detailed script verification error codes.
 */
enum script_verification_info
{
    SCRIPT_ERR_OK = 0,
    SCRIPT_ERR_UNKNOWN_ERROR,
    SCRIPT_ERR_EVAL_FALSE,
    SCRIPT_ERR_OP_RETURN,

    /* Max sizes */
    SCRIPT_ERR_SCRIPT_SIZE,
    SCRIPT_ERR_PUSH_SIZE,
    SCRIPT_ERR_OP_COUNT,
    SCRIPT_ERR_STACK_SIZE,
    SCRIPT_ERR_SIG_COUNT,
    SCRIPT_ERR_PUBKEY_COUNT,

    /* Failed verify operations */
    SCRIPT_ERR_VERIFY,
    SCRIPT_ERR_EQUALVERIFY,
    SCRIPT_ERR_CHECKMULTISIGVERIFY,
    SCRIPT_ERR_CHECKSIGVERIFY,
    SCRIPT_ERR_NUMEQUALVERIFY,

    /* Logical/Format/Canonical errors */
    SCRIPT_ERR_BAD_OPCODE,
    SCRIPT_ERR_DISABLED_OPCODE,
    SCRIPT_ERR_INVALID_STACK_OPERATION,
    SCRIPT_ERR_INVALID_ALTSTACK_OPERATION,
    SCRIPT_ERR_UNBALANCED_CONDITIONAL,

    /* BIP62 */
    SCRIPT_ERR_SIG_HASHTYPE,
    SCRIPT_ERR_SIG_DER,
    SCRIPT_ERR_MINIMALDATA,
    SCRIPT_ERR_SIG_PUSHONLY,
    SCRIPT_ERR_SIG_HIGH_S,
    SCRIPT_ERR_SIG_NULLDUMMY,
    SCRIPT_ERR_PUBKEYTYPE,
    SCRIPT_ERR_CLEANSTACK,

    /* softfork safeness */
    SCRIPT_ERR_DISCOURAGE_UPGRADABLE_NOPS,

    SCRIPT_ERR_ERROR_COUNT
};

/**
 * Verify that the transaction correctly spends the public key, considering any
 * additional constraints specified by flags.
 * @param[in]  transaction      The transaction with the script to verify.
 * @param[in]  transactionSize  The character length of the transaction.
 * @param[in]  publicKey        The script public key to verify against.
 * @param[in]  publicKeySize    The byte length of the script public key.
 * @param[in]  inputIndex       The zero-based index of the transaction input
 *                              of which the script is to be verified.
 * @param[in]  flags            Flags for additional verification constraints.
 * @param[out] code             A return code with detail for a verify fail.
 * @returns                     A script verification result with a value of
 *                              okay if the script verifies.
 */
BCX_API script_verification_result verify_script(const uint8_t* transaction,
    size_t transactionSize, const uint8_t* publicKey, size_t publicKeySize,
    uint32_t inputIndex, uint32_t flags, script_verification_info& code);

} // namespace consensus
} // namespace libbitcoin

#endif