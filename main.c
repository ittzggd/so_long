#include "so_long.h"



int main(int argc, char *argv[])
{
	t_data	*data;
	
	data = malloc(sizeof(t_data)); //이 부분은 initialize 함수로 따로 빼고 내부 멤버까지 초기화 해주기
	if(argc > 1)
	{
		set_struct(data);
		if(!make_map(argv[1], data))
			ft_error();
		window(data);
	}
}

void	set_struct(t_data *data)
{
	data->move_cnt = 0;
	data->height = 0;
	data->width = 0;
	data->sp_cnt = 0;
	data->col_cnt = 0;
	data->exit_cnt = 0;
	data->pp_x = 0;
	data->pp_y = 0;
}
