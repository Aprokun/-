type t_in_arr = array[1..10] of integer;

procedure read_arr(var arr: t_in_arr);
var i: integer;
begin
  for i := 1 to 10 do
    read(arr[i]);
end;

function is_elem_in(arr: t_in_arr; elem: integer): boolean;
var i: integer;
begin
  is_elem_in := false;
  
  for i := 1 to 10 do
    if (elem = arr[i]) then
      is_elem_in := true;  
end;

var a,b: t_in_arr;
    i, j: integer;
    f: boolean = true;
  
begin
  read_arr(a);
  read_arr(b);
  
  for i := 1 to 10 do
    if (is_elem_in(b,a[i])) and (is_elem_in(a,b[i])) and (f = true) then
      f := false;
    
  if (f = false) then
    writeln('Неверно')
  else
    writeln('Верно');
end.