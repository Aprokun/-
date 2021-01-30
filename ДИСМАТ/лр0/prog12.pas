type t_in_arr = array[1..10] of integer;

procedure read_arr(var arr: t_in_arr);
var i: integer;
begin
  for i := 1 to 10 do
    read(arr[i]);
end;

function is_elem_in(arr: t_in_arr; elem: integer; var elem_index: integer): boolean;
var i: integer;
begin
  is_elem_in := false;
  
  for i := 1 to 10 do
    if (elem = arr[i]) then
      begin
        is_elem_in := true;
        elem_index := i;
      end;
end;

var a,b,t: t_in_arr;
    f: boolean = true;
    i,k: integer;
    
begin
  writeln('Введите 10 элементов последовательности а');
  read_arr(a);
  writeln('Введите 10 элементов последовательности b');
  read_arr(b);
  
  i := 1;
  t := b;
  
  while (i <= 10) and (f = true) do
    begin
      if (is_elem_in(t,a[i],k)) then
        t[k] := 0
      else
        f := false;
      
      i := i + 1;
    end;
  
  if (f = true) then
    writeln('Верно')
  else
    writeln('Неверно');
end.