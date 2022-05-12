#pragma once
#ifndef __EOKAN_DISK__
#define __EOKAN_DISK__

#include <stdint.h>

#define SECTOR_SIZE (0x200)
#define SECTOR_BITS		9

struct part_descr* part_descr_t;
disk_descr* disk_descr_t;
struct disk_descr {
	uint64_t(*capacity)(disk_descr_t);
	int (*read) (disk_descr_t, int64_t start, int64_t num, uint8_t* buf);
	int      (*write)(disk_descr_t, int64_t start, int64_t num, const uint8_t* buf);
	void     (*release)(disk_descr_t);
};

/* disk open flags */
#define DISK_FLAG_READ      (1<<0)
#define DISK_FLAG_WRITE     (1<<1)
struct disk_probe_spec {
	const char* name;
	size_t size;
	int    (*probe)(disk_descr_t, const char* path, uint32_t flags);
};

disk_descr_t disk_open(const char* type, const char* path, uint32_t flags);
void         disk_close(disk_descr_t disk);
int          disk_read(disk_descr_t, int64_t start, int64_t num, uint8_t* buf);
int          disk_write(disk_descr_t, int64_t start, int64_t num, const uint8_t* buf);
part_descr_t disk_get_partition(disk_descr_t, int no);

struct part_descr {
	disk_descr_t disk;
	uint64_t     off;
	uint64_t     length;
};

int  part_read(part_descr_t, int64_t start, int64_t num, uint8_t* buf);
int  part_write(part_descr_t, int64_t start, int64_t num, const uint8_t* buf);
void part_close(part_descr_t);
#endif
