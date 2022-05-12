#pragma once
#ifndef __XOKAN_UTILS_H__
#define __XOKAN_UTILS_H__
struct filesys_descr;

#define MIN(a, b) ((a) > (b) ? (b) : (a))

int utf16_to_utf8(const wchar_t* utf16, size_t is, char* utfc, size_t os);
int utf8_to_utf16(const char* utfc, size_t is, wchar_t* utf16, size_t os);

int eokan_load(int debug);
void eokan_unload();
int eokan_umount(int c);
int eokan_main(struct filesys_descr* fs, int drive);

#endif