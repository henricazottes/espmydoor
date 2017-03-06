import $ from 'jquery'
const jQuery = $
window.$ = $
window.jQuery = jQuery

const head = () => (
  "<head> \
    <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css' /> \
    <link rel='stylesheet' href='http://bit.ly/2lZIUoE' /> \
    <script src='https://cdnjs.cloudflare.com/ajax/libs/materialize/0.97.8/js/materialize.min.js' /> \
  </head>"
)

const body = () => (
  "<body> \
    <div id='a'> \
      <div class='container' style='text-align: center'> \
        <div class='row'> \
          <div class='col s1 m3' /> \
          <div class='col s12 m6'> \
            <div class='card blue'> \
              <div class='card-content white-text'> \
                <span class='card-title'> \
                  <h1>Shazam <i class='fa fa-unlock-alt' aria-hidden='true' /></h1> \
                </span> \
                <p style='text align: left'>Press the button to open the door !</p> \
              </div> \
              <div class='card-action'> \
                <a style='margin: auto' onclick=" + openTheDoor() + "' class='waves-effect waves-light btn-large'>Open</a> \
              </div> \
              <br /> \
            </div> \
            <div class='card green'> \
              <div class='card-content white-text'> \
                <p style='text align: left'><i class='fa fa-check' aria-hidden='true' /> Success :D</p> \
              </div> \
            </div> \
            <div class='card red'> \
              <div class='card-content white-text'> \
                <p style='text align: left'><i class='fa fa-times' aria-hidden='true' /> Failure... :(</p> \
              </div> \
            </div> \
          </div> \
          <div class='col s1 m3' /> \
        </div> \
      </div> \
    </div> \
  </body>")

const openTheDoor = () => {
  $.get('http://192.168.43.118/openTheDoor', function (data) {
    console.log('Success: ' + data)
  })
  .done(function () {
    console.log('second success')
  })
  .fail(function () {
    console.log('error')
  })
}

$(head()).appendTo('html')
$(body()).appendTo('html')
