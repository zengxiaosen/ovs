/*
 * Copyright (c) 2009 Nicira Networks.
 * Distributed under the terms of the GNU GPL version 2.
 *
 * Significant portions of this file may be copied from parts of the Linux
 * kernel, by Linus Torvalds and others.
 */

#ifndef BRC_SYSFS_H
#define BRC_SYSFS_H 1

struct datapath;
struct net_bridge_port;

/* brc_sysfs_dp.c */
int brc_sysfs_add_dp(struct datapath *dp);
int brc_sysfs_del_dp(struct datapath *dp);

/* brc_sysfs_if.c */
int brc_sysfs_add_if(struct net_bridge_port *p);
int brc_sysfs_del_if(struct net_bridge_port *p);

#include <linux/version.h>
#if LINUX_VERSION_CODE == KERNEL_VERSION(2,6,18)
#define SUPPORT_SYSFS 1
#else
/* We only support sysfs on Linux 2.6.18 because that's the only place we
 * really need it (on Xen, for brcompat) and it's a big pain to try to support
 * multiple versions. */
#endif

#endif /* brc_sysfs.h */

