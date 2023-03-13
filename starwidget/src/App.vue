<template>
  <div>
    <div v-for="product in products" :key="product.id">
      <h3>{{ product.name }}</h3>
      <StarRating :rating="product.rating" :product-id="product.id" @rating-submitted="submitRating"></StarRating>
    </div>
  </div>
</template>

<script>
import StarRating from './components/FiveWidget.vue'
import '@fortawesome/fontawesome-free/css/all.css'

export default {
  components: {
    StarRating
  },
  data() {
    return {
      products: [
        { id: '123', name: 'Product 1', rating: 3 },
        { id: '456', name: 'Product 2', rating: 0 }
      ]
    };
  },
  methods: {
    submitRating(rating, productId) {
      // TODO: send rating and productId to server to record rating
      // Update product rating after submission
      const productIndex = this.products.findIndex(product => product.id === productId);
      if (productIndex >= 0) {
        this.products[productIndex].rating = rating;
      }
    }
  }
}
</script>
