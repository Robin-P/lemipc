/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** include
*/

#ifndef LEMIPC_H_
#define LEMIPC_H_

#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>

#define MAP_SIZE 30
#define MAP_MALLOC (MAP_SIZE + 1) * MAP_SIZE
#define CHARPOS(x, y) (x) + (y) * (MAP_SIZE + 1)
#define TRUE 1
#define FALSE 0
#define MSG_TEAM_MAX 10
#define MSG_SIZE 32


typedef struct s_data {
	char map[MAP_MALLOC];
	int msg[MSG_TEAM_MAX];
} t_data;

typedef struct s_position {
	int x;
	int y;
} t_position;

typedef struct s_msg {
	long int mtype;
	char str[MSG_SIZE];
} t_msg;

typedef struct s_id {
	key_t key;
	int shm_id;
	int sem_id;
} t_id;

typedef struct s_player {
	t_position pos;
	int order;
	int key;
	int team;
	char id;
	char isAlive;
	struct sembuf sops;
	int sem_id;
	t_msg msg;
	int msg_id;
} t_player;

void endGame(t_player *player, t_data *data);
int checkThis(int x, int y, char id, char *map);
int end(int msg_id, struct sembuf *sops, int sem_id);
void iAmAlive(t_player *player, t_data *data);
char *parse_order(char *str, char *search);
void remove_msg(int msg_id, t_msg *msg, int team);
char *get_msg(int msg_id, t_msg *msg, int team);
int get_this_msg(int msg_id, t_msg *msg, int team, char *request);
void set_msg(int team, char *to_send, int msg_id, t_msg *msg);
int move_player(t_player *player, char *map);
int createSem(key_t key);
void createMsg(key_t key, t_data *data);
int game_loop(t_id *id, t_data *data);
int create_player(t_data *data, t_id *id, int team_number);
void unlockSem(struct sembuf *sops, int sem_id);
void lockSem(struct sembuf *sops, int sem_id, int value);
void show_map(char *map, size_t side);
char *createMap(char *map, size_t side);
int error(int value);
int error_msg(char *msg, int value);
int usage(int value);
int lemipc(char *path, int team_number);
void set_order(t_player *player, t_position start, char *map);
void get_order(t_player *player, char *map);
int find_target(t_player *player, t_position start, char *map);
#endif /* !LEMIPC_H_ */
