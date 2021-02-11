type  t_arr = array[1..20] of integer;

procedure read_arr(var arr: t_arr; n: integer);
var i: integer;
begin
  for i := 1 to n do
    read(arr[i]);
end;

procedure print_arr(var arr: t_arr; n: integer);
var i: integer;
begin
  for i := 1 to n do
    if (arr[i] <> 0) then
      write(arr[i],' ');  
end;

function is_elem_in(arr: t_arr; n: integer; elem: integer): boolean;
var i: integer;
    f: boolean;
begin
  f := false;
  i := 1;
  
  while (f = false) and (i <= n) do
    begin
      if (elem = arr[i]) then
        begin
          is_elem_in := true;
          f := true;
        end;
      i := i + 1;
    end;  
end;

var a,b,c: t_arr;;
    i: integer;
  
begin
  writeln('Введите 10 элементов последовательности а');
  read_arr(a);
  writeln('Введите 10 элементов последовательности b');
  read_arr(b);
  
  for i := 1 to 10 do
    if not(is_elem_in(b,a[i])) then
      c[i] := a[i];
    
  print_arr(c);
end.