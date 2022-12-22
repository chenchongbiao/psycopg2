/* aix_support.h - definitions for aix_support.c
 *
 * Copyright (C) 2017 My Karlsson <mk@acc.umu.se>
 * Copyright (c) 2018-2019, Joyent, Inc.
 * Copyright (C) 2020-2021 The Psycopg Team
 *
 * This file is part of psycopg.
 *
 * psycopg2 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link this program with the OpenSSL library (or with
 * modified versions of OpenSSL that use the same license as OpenSSL),
 * and distribute linked combinations including the two.
 *
 * You must obey the GNU Lesser General Public License in all respects for
 * all of the code used other than OpenSSL.
 *
 * psycopg2 is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 */
#ifndef PSYCOPG_AIX_SUPPORT_H
#define PSYCOPG_AIX_SUPPORT_H

#include "psycopg/config.h"

#ifdef _AIX
#include <sys/time.h>

#ifndef timeradd
extern HIDDEN void timeradd(struct timeval *a, struct timeval *b, struct timeval *c);
extern HIDDEN void timersub(struct timeval *a, struct timeval *b, struct timeval *c);
#endif

#ifndef timercmp
#define timercmp(a, b, cmp)          \
  (((a)->tv_sec == (b)->tv_sec) ?    \
   ((a)->tv_usec cmp (b)->tv_usec) : \
   ((a)->tv_sec  cmp (b)->tv_sec))
#endif
#endif

#endif /* !defined(PSYCOPG_AIX_SUPPORT_H) */
