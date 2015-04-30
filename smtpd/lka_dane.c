/*	$OpenBSD$	*/

/*
 * Copyright (c) 2015 Gilles Chehade <gilles@poolp.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/types.h>
#include <sys/queue.h>
#include <sys/tree.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/uio.h>

#include <netinet/in.h>

#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <event.h>
#include <imsg.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <pwd.h>
#include <resolv.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "smtpd.h"
#include "log.h"
#include "ssl.h"

/* DANE support */
/*
 * Bringing DANE support to OpenSMTPD is relatively simple as soon as
 * ASR supports TLSA RR.
 *
 * This file contains the OpenSMTPD-side DANE verification which will
 * be plugged in the lookup process when ASR is ready.
 *
 * THIS IS A WORK IN PROGRESS, NOT THE ACTUAL FINAL CODE.
 *
 * -- gilles@
 *
 */

struct tlsa {
	uint8_t		usage;
	uint8_t		selector;
	uint8_t		matching_type;
	unsigned char  *data;
	size_t		dlen;
};

static int
lka_dane_verify(struct tlsa *tlsa, X509 *cert)
{
	unsigned char  *data;
	size_t		dlen;

	/* First, check usage and understand how it works */
	goto fail;


fail:
	return 0;
}
