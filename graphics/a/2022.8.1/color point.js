vertex =
`attribute vec4 a_Position;
void main()
{
  gl_Position = a_Position;
  gl_PointSize = 10.0;
}`;

fragment =
`precision mediump float;
uniform vec4 u_FragColor;
void main() 
{
  gl_FragColor = u_FragColor;
}`;

function main() 
{
  canvas = document.getElementById('color point');
  gl = canvas.getContext('webgl');
  shader_init(gl, vertex, fragment);
  a_Position = gl.getAttribLocation(gl.program, 'a_Position');
  u_FragColor = gl.getUniformLocation(gl.program, 'u_FragColor');
  canvas.onmousedown = function(ev){ click(ev, gl, canvas, a_Position, u_FragColor) };
  gl.clearColor(0.0, 0.0, 0.0, 1.0);
  gl.clear(gl.COLOR_BUFFER_BIT);
}

point = [];
color = [];
function click(ev, gl, canvas, a_Position, u_FragColor) 
{
  x = ev.clientX; 
  y = ev.clientY;
  rect = ev.target.getBoundingClientRect();
  x = ((x - rect.left) - canvas.width / 2) / (canvas.width / 2);
  y = (canvas.height / 2 - (y - rect.top)) / (canvas.height / 2);
  point.push([x, y]);
  if(x >= 0.0 && y >= 0.0)  /* 1st quadrant */
    color.push([1.0, 0.0, 0.0, 1.0]); /* red */
  else if(x < 0.0 && y < 0.0) /* 3rd quadrant */
    color.push([0.0, 1.0, 0.0, 1.0]); /* green */
  else                        
    color.push([1.0, 1.0, 1.0, 1.0]); /* white */
  gl.clear(gl.COLOR_BUFFER_BIT);
  for(i = 0; i < point.length; ++i)
  {
    xy = point[i];
    rgba = color[i];
    gl.vertexAttrib3f(a_Position, xy[0], xy[1], 0.0);
    gl.uniform4f(u_FragColor, rgba[0], rgba[1], rgba[2], rgba[3]);
    gl.drawArrays(gl.POINTS, 0, 1);
  }
}
