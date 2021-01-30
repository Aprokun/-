type t_in_arr = array[1..10] of integer;
     t_out_arr = array[1..20] of integer;

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

procedure print_arr(arr: t_out_arr);
var i: integer;
begin
  for i := 1 to 20 do
    write(arr[i],' ');  
end;

procedure insertion_sort(var arr: t_out_arr);
var i,j,key: integer;
begin
  for i := 1 to 20 do
    begin
      key := arr[i];
      j := i - 1;
      while (j >= 1) and (arr[j] > key) do
        begin
          arr[j+1] := arr[j];
          j := j - 1;
        end;
      arr[j+1] := key;
    end;
end;

var a,b: t_in_arr;
    c: t_out_arr;
    i: integer;
  
begin
  writeln('Введите 10 элементов последовательности а');
  read_arr(a);
  writeln('Введите 10 элементов последовательности b');
  read_arr(b);
  
  for i := 1 to 10 do
    if not(is_elem_in(b,a[i])) then
      c[i] := a[i];

  insertion_sort(c);
    
  print_arr(c);
end.