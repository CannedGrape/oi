Const
    OutFile	= 'dune.in';
    N          = 50;
    M          = 1000;

Type
    Tmap       = array[1..N , 1..N] of boolean;
    Tvisited	= array[1..N] of boolean;

Var
    map        : Tmap;
    visited    : Tvisited;
    p1 , p2 ,
    i , j , sum: longint;

procedure dfs(p : longint);
var
    i          : longint;
begin
    visited[p] := true;
    for i := 1 to N do
      if map[p , i] and not visited[i] then
        dfs(i);
end;

function check : boolean;
begin
    fillchar(visited , sizeof(visited) , 0);
    dfs(1);
    for i := 1 to N do
      if not visited[i] then
        exit(false);
    exit(true);
end;

Begin
    randomize;
    i := 1;
    while (i <= M) or not check do
      begin
          repeat
            p1 := random(N) + 1;
            p2 := random(N) + 1;
          until p1 <> p2;
          map[p1 , p2] := true;
          map[p2 , p1] := true;
          inc(i);
      end;
    assign(OUTPUT , OutFile); ReWrite(OUTPUT);
      writeln(N);
      for i := 1 to N do
        begin
            sum := 0;
            for j := 1 to N do
              if map[i , j] then
                inc(sum);
            write(sum);
            for j := 1 to N do
              if map[i , j] then
                write(' ' , j);
            writeln;
        end;
    Close(OUTPUT);
End.
