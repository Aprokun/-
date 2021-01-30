type t_in_arr = array[1..10] of integer;
     t_out_arr = array[1..20] of integer;

procedure read_arr(var arr: t_in_arr);
var i: integer;
begin
  for i := 1 to 10 do
    read(arr[i]);
end;

procedure union_arrs(var c: t_out_arr; a: t_in_arr; b: t_in_arr);
var i: integer;
begin
  for i := 1 to 10 do
    c[i] := a[i];
  for i := 1 to 10 do
    c[i+10] := b[i];
end;

procedure print_arr(arr: t_out_arr);
var i: integer;
begin
  for i := 1 to 20 do
    write(arr[i],' ');  
end;

procedure merge(var arr: t_out_arr; first, last: integer);
var middle, start, final, j: integer;
    mas: t_out_arr;
begin
  middle:=(first+last) div 2; {делим массив}
  start:=first; {начало левой части}
  final:=middle+1; {начало правой части}
  for j:=first to last do {от начала до конца}
    if (start<=middle) and ((final>last) or (arr[start]<arr[final])) then
      begin
        mas[j]:=arr[start];
        inc(start);
      end
    else
      begin
        mas[j]:=arr[final];
        inc(final);
      end;
      
for j:=first to last do arr[j]:=mas[j];
end;


procedure merge_sort(var arr: t_out_arr; first, last: integer);
begin
if first<last then
 begin
  merge_sort(arr, first, (first+last) div 2); {сортируем левую часть}
  merge_sort(arr, (first+last) div 2+1, last); {сортируем правую часть}
  merge(arr, first, last); {сливаем две части}
 end;
end;

var a,b: t_in_arr;
    c: t_out_arr;
  
begin
  writeln('Введите 10 элементов последовательности а');
  read_arr(a);
  writeln('Введите 10 элементов последовательности b');
  read_arr(b);
  
  union_arrs(c,a,b);
  merge_sort(c,1,20);
    
  print_arr(c);
end.