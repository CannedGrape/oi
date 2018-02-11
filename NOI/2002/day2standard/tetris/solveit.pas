{ SOLVEIT.PAS for TETRIS  by Rujia Liu }
const
  Size=5*5*5*5*5;

procedure solve2(from:integer);
begin
  while Num[from]<>Num[from+1] do
  begin
    if Num[from]=Num[from+1]+2 then WriteCommand(17,from)
    else if Num[from+1]=Num[from]+2 then WriteCommand(16,from)
    else if Num[from]>Num[from+1] then WriteCommand(1,from+1)
    else if Num[from+1]>Num[from] then WriteCommand(1,from);
  end;
end;

procedure SolveIt(Width,ck,from:integer);
var
  Count,CC:array[1..5] of integer; {5*5*5*5*5=3125}
  Prev,QT,QC:array[0..Size-1] of integer;

function MyCanPut(t,c:longint):boolean;
var i:integer;
begin
  MyCanPut:=false;
  {check column c~c+length(check)-1}
  if c+length(check[t])-1>Width then Exit;
  for i:=2 to length(check[t]) do
    if ord(check[t,1])-ord(check[t,i])<>Count[c]-Count[c-1+i] then Exit;
  MyCanPut:=true;
end;

procedure MyPutIt(t,c,flag:integer);
var i:integer;
begin
  for i:=1 to length(check[t]) do
    Count[c-1+i]:=Count[c-1+i]+(ord(Add[t,i])-ord('0'))*flag;
end;

procedure DoCommand(H:integer);
begin
  if Prev[H]<>-1 then
  begin
    DoCommand(Prev[H]);
    WriteCommand(QT[H],from-1+QC[H]);
  end;
end;

procedure bfs;
var get,put:integer;
    Hash:array[0..Size] of boolean;
    Q:array[0..Size] of integer;
    ok1,ok2,found:boolean;
    i,Min,H,HH:integer;
    t,c:integer;
begin
  fillchar(Hash,sizeof(Hash),0);
  H:=0;     for i:=1 to Width do H:=H*5+Count[i];
  get:=0;   put:=1;
  Q[0]:=H;  Prev[H]:=-1;  Hash[H]:=true;
  while get<>put do
  begin
    H:=Q[get];
    for i:=Width downto 1 do
    begin
      Count[i]:=H mod 5;
      H:=H div 5;
    end;
    H:=Q[get];   inc(get);
    for t:=1 to 19 do
      for c:=1 to Width do {need to put on column 5}
        if MyCanPut(t,c) then
        begin
          MyPutIt(t,c,1);
          { Prepare }
          ok1:=true;
          Min:=maxint;
          for i:=1 to Width do
            if Count[i]<Min then Min:=Count[i];
          { Check 1 }
          for i:=1 to Width do
            if Count[i]>Min+4 then ok1:=false;
          if ok1 then
          begin
            for i:=1 to Width do CC[i]:=Count[i]-Min;
            HH:=0;
            for i:=1 to Width do HH:=HH*5+CC[i];
            { Check 2 }
            if not Hash[HH] then
            begin
              Hash[HH]:=true;
              Q[Put]:=HH;    inc(Put);
              Prev[HH]:=H;   QT[HH]:=t;    QC[HH]:=c;
              ok2:=true;
              for i:=2 to ck do
                if CC[1]<>CC[i] then ok2:=false;
              if ok2 then
              begin
                DoCommand(HH);
                exit;
              end;
            end;
          end;
          MyPutIt(t,c,-1);
        end;
  end;
end;

procedure preprocess;
var ok:boolean;
    i,Min:integer;
begin
  {Make The Difference Between 0 and 3}
  while true do
  begin
    ok:=true;
    Min:=maxint;
    for i:=1 to Width do
      if Num[from-1+i]<Min then Min:=Num[from-1+i];
    for i:=1 to Width do
      if Num[from-1+i]>Min+3 then ok:=false;
    if ok then break;
    for i:=1 to Width do
      if Num[from-1+i]=Min then
      begin
        writeln(f,1,' ',from-1+i);
        Num[from-1+i]:=Num[from-1+i]+4;
      end;
  end;
  { Prepare }
  Min:=maxint;
  for i:=1 to Width do
    if Num[from-1+i]<Min then Min:=Num[from-1+i];
  for i:=1 to Width do
    Count[i]:=Num[from-1+i]-Min;
end;

var
  over:boolean;
  i:integer;
begin
  over:=true;
  for i:=2 to ck do
    if Num[from]<>Num[from-1+i] then over:=false;
  if over then exit;
  preprocess;
  bfs;
end;