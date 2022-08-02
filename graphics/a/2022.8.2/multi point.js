vertex =
`attribute vec4 a_Position;
void main() 
{
  gl_Position = a_Position;
  gl_PointSize = 10.0;
}`;

fragment =
`void main() 
{
  gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}`;

function main() 
{  
  canvas = document.getElementById('webgl');
  gl = canvas.getContext('webgl');
  shader_init(gl, vertex, fragment);
  n = vertex_buffer_init(gl);
  gl.clearColor(0, 0, 0, 1);
  gl.clear(gl.COLOR_BUFFER_BIT);
  gl.drawArrays(gl.POINTS, 0, n);
}

function vertex_buffer_init(gl) 
{
  vertices = new Float32Array
  ([
    0.0, 0.5,   
    -0.5, -0.5,
    0.5, -0.5
  ]);
  n = vertices.length / 2;
  vertexBuffer = gl.createBuffer();
  gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer); /* bind the buffer object to target */
  gl.bufferData(gl.ARRAY_BUFFER, vertices, gl.STATIC_DRAW); /* write data into the buffer object */
  a_Position = gl.getAttribLocation(gl.program, 'a_Position'); /* assign buffer object to a_Position */
  gl.vertexAttribPointer(a_Position, 2, gl.FLOAT, false, 0, 0); /* enable assignment to a_Position */
  gl.enableVertexAttribArray(a_Position); 
  return n;
}
