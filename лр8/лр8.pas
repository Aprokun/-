const
    days: array[1..7] of string = ('понедельник','вторник','среда','четверг','пятница','суббота','воскресенье');
type date = record
    d, m, y, dw: integer;
end;

function isLeap(year: integer) : boolean;
var res: boolean;
begin
  if (year mod 100 = 0) then
    if (year mod 400 = 0) then
      res := true
    else
      res := false
  else
    if (year mod 4 = 0) then
      res := true
    else
      res := false;
 isLeap := res;
end;

function days_in_month(month: integer; year: integer) : integer;
var res: integer;
begin
  case month of
    1, 3, 5, 7, 8, 10, 12: res := 31;
    4, 6, 9, 11: res := 30;
  end;
  if (month = 2) then
    begin
      if (isLeap(year) = true) then
        res := 29
      else 
        res := 28;
    end;
  days_in_month := res;
end;

function count_dw(total_d: integer; dw: integer) : integer;
begin
total_d := total_d mod 7;
while (total_d <> 1) do
  begin
    dw := dw - 1;
    
    if (dw = 0) then 
      dw := 7;
    
    total_d := total_d - 1;
  end;
  
  count_dw := dw;  
end;

var 
  evnt: date;
  t, cn, total_d, num_d: integer;
  
begin
  cn := 1;
  
  writeln('Введите дату');
  
  write('День: '); read(evnt.d);
  write('Месяц: '); read(evnt.m);
  write('Год: '); read(evnt.y);
  write('День недели (число, где 1 - понедельник, 2 - вторник и т.д.): '); read(evnt.dw);
  
  total_d := evnt.d;
  
  while cn < evnt.m do
    begin
      t := days_in_month(cn,evnt.y);
      total_d := total_d + t;
      cn := cn + 1;
    end;
  
  num_d := count_dw(total_d,evnt.dw);
  
  writeln(days[num_d]);
end.
